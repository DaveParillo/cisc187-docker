//
// A simple program to echo standard input to standard out
// Options:
//  - Program can repeat the number of times to echo input
//  - Program can run interactively and echo input received 1 line at a time
//
#include <cstring>
#include <iostream>
#include <string>

/**
 * Display a usage statement for this program.
 */
static void usage(const char* name);
/**
 * Explain how to use this program
 */
static void help(const char* name);

/**
 * Parse command line and return the repeat count.
 */
unsigned process_args(int argc, char** argv);

/**
 * Echo input received 'repeat' number of times.
 */
int echo(unsigned repeat);


int main(int argc, char** argv) {
  auto repeat = process_args(argc, argv);
  return echo(repeat);
}


static void usage(const char* name) {
  std::cerr << "Usage: " << name << " [-h] [-r #repeats]\n";
}

static void help(const char* name) {
  usage(name);
  std::cerr << "Options:\n"
    << "  -h   Show this text\n"
    << "  -r   Set the number of times to repeat the text.  Default = 1.\n"
    << std::endl;
  exit(0);
}

unsigned process_args(int argc, char** argv) {
  unsigned repeat = 1;
  for (int i=1; i < argc; ++i) {
    if (!std::strncmp(argv[i], "-h", 2)) {
      help(argv[0]);
    } else if (!std::strncmp(argv[i], "-r", 2)) {
      ++i;
      if (i < argc) {
        repeat = atoi(argv[i]);
      } else {
        std::cerr << "Error using '-r' argument: no repeat specified\n";
        usage(argv[0]);
      }
    }
  }
  return repeat;
}

int echo(unsigned repeat) {
  std::string line;
  while (getline(std::cin, line)) {
    for (auto i = 0ul; i < repeat; ++i) {
      std::cout << line << '\n';  // getline strips newline
    }
    line.clear();
  }
  return 0;
}

