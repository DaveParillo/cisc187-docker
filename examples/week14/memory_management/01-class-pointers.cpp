#include <iostream>
#include <string>

class Hello {
  public: 
    Hello ()              
      : name_{ "Alice"} {}
    explicit Hello (const std::string& n) 
      : name_ {n} {}

    std::string name() const {
      return name_;
    }
    void name(const std::string& n) {
      name_ = n;
    }

  private:
    std::string name_;
};

int main()
{
  Hello  alice;
  Hello* ptr_to_alice = &alice;

  std::cout << "Hello, " << alice.name()           << "!\n";
  std::cout << "Hello, " << (*ptr_to_alice).name() << "!\n";
  std::cout << "Hello, " << ptr_to_alice->name()   << "!\n";
  return 0;
}
