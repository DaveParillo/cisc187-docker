#include <cstdio>
#include <fstream>
#include <string>

void write_binary(const int& obj, const std::string& fname);
void read_binary(int& obj, const std::string& fname);

int main() {
  int x, y;
  std::string filename = "test.bin";

  x = 123;
  puts("about to write 123");;
  write_binary(x, filename);

  puts("about to read 123");;
  read_binary(y, filename);

  printf("original: %d, copy: %d\n", x, y);

  return 0;
}

// passing a const ref requires const cast
void write_binary(const int& obj, const std::string& fname) {
  using std::ios;
  std::ofstream fileout(fname, ios::out|ios::binary|ios::ate);

  //fileout.write(reinterpret_cast<char *>(&obj), sizeof(int));
  fileout.write(reinterpret_cast<char *>(const_cast<int*>(&obj)), sizeof(int));
  fileout.close();
}

void read_binary(int& obj, const std::string& fname) {
  using std::ios;
  std::ifstream filein(fname, ios::binary|ios::in);
  filein.read(reinterpret_cast<char *>(&obj) ,sizeof(int));
  filein.close();
}


