#pragma once

#include <string>

class Hello {
  public: 
    Hello ();
    Hello (std::string n);
    ~Hello ();

    std::string name() const        { return name_; }
    void        name(std::string n) { name_ = n; }

  private:
    std::string name_;
};

