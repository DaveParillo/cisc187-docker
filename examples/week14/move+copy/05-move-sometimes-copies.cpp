#include <iostream>
#include <utility>

// from http://cppquiz.org/quiz/question/112
//
// Sometimes a member cannot be moved by an objects move constructor.
//
// See: http://isocpp.org/blog/2012/11/universal-references-in-c11-scott-meyers
// for some gory details
//

struct A {
	A() { std::cout << "1"; }
	A(const A&) { std::cout << "2"; }
	A(A&&) { std::cout << "3"; }
};

struct B {
	A alice;
	B() { std::cout << "4"; }
	B(const B& other) : alice(other.alice) { std::cout << "5"; }
	B(B&& other) : alice(other.alice) { std::cout << "6"; }
};

int main() {
	B bob;
	B barb = std::move(bob);
}

