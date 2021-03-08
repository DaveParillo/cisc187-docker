
//
// This is example code from Chapter 4.6.2 "A numeric example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//


#include <iostream>
#include <vector>

//------------------------------------------------------------------------------

// read some temperatures into a vector
int main()
{
  std::vector<double> temps;         // temperatures
  double temp;
  while (std::cin>>temp)             // read 
      temps.push_back(temp);    // put into vector
    // ... do something ...
}

//------------------------------------------------------------------------------
