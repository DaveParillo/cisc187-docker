#include <cstdio>

// calc.h
class calc {
  double* p;
  double* res;
  public:
  calc() = delete;
  calc(int res_size, int max);
  ~calc();
  double* calculate();
};

// calc implementation
calc::calc(int res_size, int max)
  : p {new double[max]} ,
  res {new double[res_size]} {
    for (int i = 0; i< res_size; ++i) {
      res[i] = i;
    }
  }
calc::~calc() {
  puts("destroying calc resources");
  delete [] p;
  delete [] res;
  res = nullptr;
}
double* calc::calculate() {
  // use p to calculate results to be put in res
  return res;
}

int main() {
  double* r = nullptr;

  {  // define a scope to contain calc
    calc c = {100,1000};  // acquire resource
    r = c.calculate();
    printf("some r is: %.2f\n", r[42]);
  }  // delete resource
}

