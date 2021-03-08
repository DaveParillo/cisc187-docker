#pragma once

#include <iosfwd>
#include <string>

// A POD for a God
struct God {
    God() = default;
    God(const std::string& n, const std::string& m, const std::string& v, const std::string& w)
        : name(n), mythology(m), vehicle(v), weapon(w) { }
    std::string name;
    std::string mythology;
    std::string vehicle;
    std::string weapon;
};

std::ostream& operator<<(std::ostream& os, const God& g);



