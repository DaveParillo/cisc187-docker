#include <cstdio>
#include <memory>
#include <vector>

#include "make_unique.h"

using std::vector;

std::unique_ptr<vector<double>>
calc(const int res_size, const int max) {
  double* p = new double[max];        //temp memory
  auto res = mesa::make_unique <vector<double>>();

  for (int i = 0; i< res_size; ++i) {
    res->push_back(i);
  }

  // use p to calculate results to be put in res
  delete[] p;    // free temp memory 
  return std::move(res);    // return and transfer ownership
}

int main() {
  auto r = calc(100,1000);
  printf("some r is: %.2f\n", r->at(42));
}

