#include <unistd.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/**
 *   Attempt to open a file, and list it's contents.
 */ 
void        process_file(const std::string& fname);

/**
 * read integers from ist into v until we reach eof() or terminator character
 * Note that this function takes istream, not ifstream...
 */
bool        fill_vector(std::istream& ist, std::vector<int>& v, char terminator);
static void show_usage (const std::string& name);

int main(int argc, char* argv[])
{
  int c;
  std::string iname = "vector_inputs.txt";

  while ((c = getopt (argc, argv, "hf:")) != -1) {
    switch (c) {
      case 'f':
        iname = optarg;
        break;
      case 'h':
      default:
        show_usage(argv[0]);
    }
  }
  process_file(iname);

  return 0;
}

void process_file(const std::string& fname)
{
  std::ifstream ist {fname};  // ifstream is an “input stream from a file”
                              // defining an ifstream with a name string
                              // opens the file of that name for reading
  if (!ist) {
    std::cerr << "can’t open input file " << fname << std::endl;
  } else {
    std::vector<int> numbers;
    if(fill_vector(ist, numbers, 'q')) {
      std::cout << "Values read from file:" << std::endl;
      for (int i: numbers) {
        std::cout << i << std::endl;
      } 
    } else {
      std::cerr << "Could not process file " << fname << std::endl;
    }
  }
}



bool fill_vector(std::istream& ist, std::vector<int>& v, char terminator)
{
  for (int i; ist >> i; )             // read until “some failure”
    v.push_back(i);                   // store in v
  if (ist.eof()) return true;         // fine: we found the end of file
  if (ist.bad()) {
    std::cerr <<"ist is bad\n";       // stream corrupted;
  } else if (ist.fail()) {            // clean up the mess as best we can and report the problem
    ist.clear();                      // clear stream state,  so that we can look for terminator
    char c;
    ist >> c;                               // read a character, hopefully terminator
    if (c == terminator) {                  // unexpected character
      ist.clear(std::ios_base::goodbit);    // set the state to good()
    } else {  
      ist.clear(std::ios_base::failbit);    // set the state back to fail()
    }
  }
  return ist.good();        // messy, but we made it!
}



static void show_usage(const std::string& name) {
  std::cerr << "Usage: " << name << " [-h] [-r #] [-n NAME]\n"
    << "Options:\n"
    << "  -h   Show this text\n"
    << "  -f   Process the named file.  defaults to 'vector_inputs.txt'\n"
    << std::endl;
  exit(0);
}

