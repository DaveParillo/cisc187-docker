#include <iostream> 

int main () 
{
  double funds = 1.00;
  int items = 0;

  for (double price = 0.10; funds >= price; price += 0.10) 
  {
    funds -= price;
    ++items;
  }

  std::cout << "bought " << items << " items.\n";
  std::cout << "change " << funds << " cents.\n";
  return 0;

}


