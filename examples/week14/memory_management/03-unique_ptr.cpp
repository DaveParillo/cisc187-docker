#include <cstdio>
#include <memory>

struct Foo {
  Foo()            {puts("Foo::Foo");}
  ~Foo()           {puts("Foo::~Foo");}
  void bar() const {puts("Foo::bar");}
};

void f (const Foo& x) {
  puts("f (const Foo&)");
  x.bar();
}

int main()
{
  std::unique_ptr<Foo> p1(new Foo);          // p1 owns Foo
    if (p1) p1->bar();

  {                                          // a scope for p2
    std::unique_ptr<Foo> p2(std::move(p1));  // now p2 owns Foo
      f(*p2);

    p1 = std::move(p2);                      // now p1 owns Foo
  }                                          // p2 scope ends
  puts("destroyed p2");

  if (p1) p1->bar();
}  
