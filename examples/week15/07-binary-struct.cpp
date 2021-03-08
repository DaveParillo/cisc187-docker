#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct test {
  int16_t a;
  double b;
  char c[25];
  std::string d;
};

void write_binary(test& obj, std::string& fname);
void read_binary (test& obj, std::string& fname);
std::ostream& operator<<(std::ostream& os, const test& rhs);

int main()
{
  std::string filename = "test.bin";
  test mine;
  char hi[] = "Hello World!";

  mine.a = 42;
  mine.b = 2.781828;
  std::copy(hi,hi+sizeof(hi)/sizeof(hi[0]), mine.c);
  mine.d = filename;

  std::cout << "about to write (struct 'mine'):\n";
  std::cout << mine << std::endl;
  write_binary(mine, filename);

  test yours;
  std::cout << "\nbefore read (unitialized struct 'yours'):\n";
  std::cout << yours << std::endl;
  read_binary(yours, filename);

  std::cout << "after:\n";
  std::cout << yours << std::endl;

  std::cout << "done.\n";
  return 0;
}

void write_binary(test& obj, std::string& fname) {
  using std::ios;
  std::ofstream fileout(fname, ios::out|ios::binary|ios::ate);

  fileout.write(reinterpret_cast<char *>(&obj), sizeof(test));
  fileout.close();
}

void read_binary(test& obj, std::string& fname) {
  std::ifstream fin(fname, fin.binary|fin.in);
  fin.read(reinterpret_cast<char *>(&obj), sizeof(test));
  fin.close();
}

std::ostream& operator<<(std::ostream& os, const test& rhs)
{
  os << rhs.a << ' ' << rhs.b << ' ' << rhs.c << ' ' << rhs.d;
  return os;
}



