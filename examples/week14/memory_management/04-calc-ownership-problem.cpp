
// calc returns a pointer to a double
// the caller is responsible for 
// the memory allocated for res
double* calc(int res_size, int max) {
  double* p = new double[max];    //temp memory
  double* res = new double[res_size];
  // use p to calculate results to be put in res
  delete[] p;    // free temp memory 
  return res;    // can't free this here!
}
int main() {
  double* r = calc(100,1000);
  // use r
  delete[] r;    // easy to forget, error prone
}

