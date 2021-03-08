// A port of a fun little java program from
// Head First Java, 2nd ed. ISBN-13: 978-0596009205
#include <iostream>
#include <random>
#include <string>
#include <vector>

int main() {
  std::random_device r;
  std::default_random_engine eng(r());
  using rand = std::uniform_int_distribution<std::uint64_t>;

  const char* list_one[] = {
    "24/7", "multi-tier", "30,000 foot", "B-to-B", "win-win",
    "front-end", "web-based", "pervasive", "smart", "six-sigma",
    "critical-path", "dynamic", "extreme", "three-tier", "agile"
  };

  // generally prefer vector over arrays
  const std::vector<std::string> list_two = {
    "empowered", "sticky", "value-added", "oriented", "centric",
    "distributed", "clustered", "branded", "outside-the-box",
    "positioned", "networked", "focused", "leveraged", "aligned",
    "targeted", "shared", "cooperative", "accelerated"
  };

  const std::vector<std::string> list_three = {
    "process", "tipping-point", "solution", "architecture",
    "core competency", "strategy", "mind-share", "portal",
    "space", "vision", "paradigm", "mission"
  };

  const std::size_t one_size = 14;  // arrays don't know their size
  auto r1 = rand {0, one_size} (eng);
  auto r2 = rand {0, list_two.size()-1} (eng);   // vectors know their size
  auto r3 = rand {0, list_three.size()-1} (eng);

  std::string phrase = {list_one[r1]};
  phrase += " " + list_two[r2] + " " + list_three[r3];

  std::cout << "What we need is a " << phrase << '\n';

  // or could have omitted temporary phrase and simply:
  // std::cout << "What we need is a " << list_one[r1] << ' '
  //                                   << list_two[r2] << ' '
  //                                   << list_three[r3] << '\n';
  return 0;
}
