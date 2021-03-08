
#include "God.h"

#include <iostream>

std::ostream& operator<<(std::ostream& os,const God& g)
{
    os << g.name << ", " << g.mythology << ", ";
    return os << g.vehicle << ", " << g.weapon << '\n';
}



