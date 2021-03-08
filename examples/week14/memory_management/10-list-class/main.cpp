#include "List.h"
#include "God.h"

#include <iostream>

using mesa::List;

// print all gods in List
template <class T>
void print_all(List<T>& list);

int main() {
  List<God> gods;
  gods.push_back ({"Thor","Norse","Pinzgauer","Mjolnir"});
  gods.push_back ({"Odin","Norse","Sleipner","Gungnir"});
  gods.push_back ({"Freyja","Norse","Chariot","Torc"});
  gods.push_back ({"Baldr","Norse","Hringhorni","Spear"});
  gods.push_back ({"Zeus","Greek","","Lightning"});
  gods.push_back ({"Artemis","Greek","Deer","Bow & arrow"});
  gods.push_back ({"Athena","Greek","","Wisdom"});
  gods.push_back ({"Poseidon","Greek","Seahorse","Trident"});
  gods.push_back ({"Hermes","Greek","Winged Sandals","Caduceus"});

  gods.push_back ({"Vishnu","Hindu","Garuda","Sudarshana Chakra"});
  gods.push_back ({"Lakshmi","Hindu","Owl and elephant","Lotus"});
  gods.push_back ({"Shiva","Hindu","Bull","Trishula (trident)"});
  gods.push_back ({"Kali","Hindu","Lion","Sword"});
  std::cout << "All Gods:\n";
  print_all(gods);

  //cheating
  //not finding by name, just by index
  List<God> norse;
  norse.push_back(gods.remove(3));
  norse.push_back(gods.remove(2));
  norse.push_back(gods.remove(1));
  norse.push_back(gods.remove(0));
  std::cout << "Norse Gods:\n";
  print_all(norse);

  List<God> greek;
  greek.push_back(gods.remove(1));
  greek.push_back(gods.remove(1));
  greek.push_back(gods.remove(2));
  greek.push_back(gods.remove(1));
  greek.push_back(gods.remove(0));
  std::cout << "Greek Gods:\n";
  print_all(greek);

  List<God> hindu;
  hindu.push_back(gods.remove(3));
  hindu.push_back(gods.remove(1));
  hindu.push_back(gods.remove(1));
  hindu.push_back(gods.remove(0));
  std::cout << "Hindu Gods:\n";
  print_all(hindu);

}

template<class T>
void print_all(List<T>& list) {
  for (int i=0; i<list.size(); ++i) {
    std::cout << list.at(i);
  }
}

