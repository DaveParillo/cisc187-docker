#include <iostream>
#include <memory>
#include <vector>

enum class Answer { NO, YES };
 
class GimmeStrategy {
public:
  virtual Answer canIHave() = 0;
  virtual ~GimmeStrategy() = default;
};
 
class AskMom : public GimmeStrategy {
public:
  Answer canIHave() override {
    std::cout << "Mommy? Can I have this?\n";
    return Answer::NO;
  }
};
 
class AskDad : public GimmeStrategy {
public:
  Answer canIHave() override {
    std::cout << "Dad, I really need this!\n";
    return Answer::NO;
  }
};
 
class AskGrandpa : public GimmeStrategy {
public:
  Answer canIHave() override {
    std::cout << "Grandpa, is it my birthday yet?\n";
    return Answer::NO;
  }
};
 
class AskGrandma : public GimmeStrategy {
public:
  Answer canIHave() override {
    std::cout << "Grandma, I really love you!\n";
    return Answer::YES;
  }
};
 
class Gimme : public GimmeStrategy {
	std::vector<std::unique_ptr<GimmeStrategy>> chain;
public:
  Gimme() {
    chain.push_back(std::unique_ptr<GimmeStrategy>(new AskMom));
    chain.push_back(std::unique_ptr<GimmeStrategy>(new AskDad));
    chain.push_back(std::unique_ptr<GimmeStrategy>(new AskGrandpa));
    chain.push_back(std::unique_ptr<GimmeStrategy>(new AskGrandma));
  }
  Answer canIHave() {
	for (const auto& it: chain) {
		if (it->canIHave() == Answer::YES) {
			return Answer::YES;
		}
	}
    // Reached end without success...
    std::cout << "Waaaaaahh!!\n";
    return Answer::NO;
  }
};
 
int main() {
  Gimme chain;
  chain.canIHave();   // no obligation to use the return value

  std::cout << "\nrun through the whole chain again:\n";
  // we can print the scoped enum return value,
  // if we cast it to an int
  std::cout << int(chain.canIHave()) << '\n';

  // there is nothing special about the objects in the chain
  // we can invoke any of them individually
  std::cout << "ask mom directly\n";
  AskMom mom;
  mom.canIHave();
}
 
 
