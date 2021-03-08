CXXFLAGS=-Wall -Wextra -pedantic -std=c++11

cards : clean
	c++ ${CXXFLAGS} -o $@ cards.cpp cards_test.cpp

enum : clean
	c++ ${CXXFLAGS} -o $@ Direction.cpp enum.cpp

clean : 
	rm -f cards enum *.o
