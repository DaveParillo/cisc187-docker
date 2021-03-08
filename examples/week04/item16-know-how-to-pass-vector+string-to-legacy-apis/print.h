#pragma once

#include <iostream>
#include <string>

template<typename Container>
void print(const std::string& name, const Container& c) {

  std::cout << name << ": \t";
  for (auto v: c) {
    std::cout << v << ' ';
  }
  std::cout << '\n';
}


