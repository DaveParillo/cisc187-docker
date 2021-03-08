
//
// This is example code from Chapter 4.6.2 "A numeric example" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <algorithm>    // std::sort
#include <iostream>
#include <vector>


//------------------------------------------------------------------------------

// compute mean and median temperatures
int main()
{
  std::vector<double> temps;        // temperatures
    double temp;
    while (std::cin>>temp)            // read 
        temps.push_back(temp);   // put into vector

    // compute mean temperature:
    double sum = 0;
    for (int i = 0; i< temps.size(); ++i) sum += temps[i];
    std::cout << "Average temperature: " << sum/temps.size() << std::endl;

    // compute median temperature:
    std::sort(temps.begin(),temps.end()); // sort temps
    // "from the beginning to the end."
    std::cout << "Median temperature: " << temps[temps.size()/2] << std::endl;
}

//------------------------------------------------------------------------------
