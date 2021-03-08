// another problem like the swap problem.cpp
// 
#include <cmath>
#include <iterator>
#include <iostream>

using namespace std;

// struct point {
// 	double x;
// 	double y;
// };

// double distance(point* p1, point* p2) {
// 	double x = p2->x - p1->x;
// 	double y = p2->y - p1->y;
// 	return std::sqrt(x*x + y*y);
// }

long distance(long* x, long* y) {
	return *y - *x;
}

int main() {
    int a = 0;
    int b = 100;
    auto d = distance (&a, &b);
	std::cout << "distance(int): " << d << std::endl;

    long e = 0;
    long f = 100;
    auto g = distance (&e, &f);
	std::cout << "distance(long): " << g << std::endl;

    // point p1 = {0,0};
    // point p2 = {100,100};
    // auto dd = distance (&p1, &p2);
	// std::cout << "distance(point): " << dd << std::endl;

    return 0;
}

