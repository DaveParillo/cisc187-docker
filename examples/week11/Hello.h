#ifndef WEEK09_HELLO_H
#define WEEK09_HELLO_H

#include <string>

#ifndef HELLO_CONSTRUCTOR

// a version of hello without specifically defining a constructor
class Hello {
  public: 
    // get the name 
    std::string name() 
    {
      return name_;
    }
    // set the name to something else
    void name(const std::string& new_name)
    {
      name_ = new_name;
    }

  private:
    std::string name_;  // this *cant* be just 'name'
                        // it would conflict with our class functions
                        // Note: the default value is to have an empty name!

};

#else

// hello-b.cpp allows for no name to be printed if name_ is never set
// A Constructor can fix that
//
class Hello {
  public: 
    Hello()               // The default constructor
    {
      name_ = "Alice";    // set the name in the body of the constructor
    }

    Hello (const std::string& initial_name)  // set name when object is declared
      : name_{initial_name} { }              // set name in initializer list (C++11)

    // get the name 
    std::string name() 
    {
      return name_;
    }
    // set the name to something else
    void name(const std::string& new_name)
    {
      name_ = new_name;
    }

  private:
    std::string name_;
};


#endif // HELLO_CONSTRUCTOR

#endif // WEEK09_HELLO_H

