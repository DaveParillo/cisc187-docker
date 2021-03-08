#include <functional>  // std::greater
#include <iostream>
#include <map>
#include <set>
#include <string>

using std::string;
void print (const std::set<string>& keys) {
    for (const auto& key: keys) {
        std::cout << key << ' ';
    }
}

template <class Comparator>
void print (const string title, const std::map<string, int, Comparator>& x) {
    std::cout << title;
    for (const auto& kvp: x) {
        std::cout << kvp.first << ", " << kvp.second << '\n';
    }
}

int main() {
    std::map<string, int> inventory {
        {"apple", 12},
            {"kiwi", 4},
            {"lemon", 1},
            {"pear", 4},
            {"peach", 4},
            {"grape", 100},
            {"cocoa", 3},
    };

    print ("Initial inventory:\n", inventory);

    std::set<string> inventory_keys;

    // extract keys from the inventory map
    for (const auto& i: inventory) {
        auto result = inventory_keys.insert(i.first);
        if (!result.second) std::cout << "no insertion\n";
    }

    std::cout << "All fruit keys:\n";
    print (inventory_keys);

    std::set<string> keys;
    auto it = inventory.upper_bound("kiwi");
    while(it != inventory.end()) {
        auto result = keys.insert(it->first);
        if (!result.second) std::cout << "no insertion\n";
        ++it;
    }
    std::cout << "\n\nAll fruit keys greater than 'kiwi':\n";
    print (keys);


    // define a reverse ordered map
    const auto greater_than = [] (string lhs, string rhs) { return lhs > rhs;};
    std::map<string, int, decltype(greater_than)> reverse_inventory1 (greater_than);

    for (auto& i: inventory) {
        reverse_inventory1.insert(i);
    }
    print ("\n\nReverse inventory using lambda:\n", reverse_inventory1);


    std::map<string, int, std::greater<string>> reverse_inventory2;
    for (auto& i: inventory) {
        reverse_inventory2.insert(i);
    }
    print ("\nReverse inventory using std::greater:\n", reverse_inventory2);


}

