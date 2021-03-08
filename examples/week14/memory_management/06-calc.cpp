#include <cstdio>
#include <memory>

double* calc(const int res_size, const int max) {
  double* p = new double[max];        //temp memory

  std::unique_ptr<double[]> res {new double[res_size]()};

  for (int i = 0; i< res_size; ++i) { res[i] = i; }

  // use p to calculate results to be put in res
  delete[] p;    // free temp memory 
  return res.release();    // give away pointer
}

int main() {
  double* r = calc(100,1000);
  printf("some r is: %.2f\n", r[42]);
  // no delete here because r is about to go out of scope
}

