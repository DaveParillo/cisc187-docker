#pragma once

#include <iostream>
#include <string>

struct Animal {
    std::string name_;
    Animal(std::string name) : name_{name} 
    {}
    virtual std::string name() const {
      return std::string("Animal name is ") + name_;
    }
};

struct Canine : public Animal {
    Canine(std::string name) : Animal{name} 
    {}
    virtual std::string name() const {
      return std::string("Canine name is ") + name_;
    }
};


struct Wolf : public Canine {
    Wolf(std::string name) : Canine{name} 
    {}
    virtual std::string name() const {
      return "Wolf name is Bob";
    }
};

void call_v (Animal a) {
    std::cout << a.name() << '\n';
}
void call_r (Animal& a) {
    std::cout << a.name() << '\n';
}
void call_cr (const Animal& a) {
    std::cout << a.name() << '\n';
}
void call_p (Animal* a) {
    std::cout << a->name() << '\n';
}


