#pragma once

#include <memory>
#include <utility>
// Constructs an object of type T and wraps it in a std::unique_ptr.
//
// make_unique is a convenient addition to C++14
//
// although not part of C++11, it's easy to add one of your own.
//
// guard against some other implementation of make_unique
namespace mesa {

  // This is a simplified implementation of the real C++14 version
  // Implementation does not disable this overload for array types
  template<typename T, typename... Args>
  std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
  }
}



