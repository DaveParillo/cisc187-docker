CXX = c++
CXXFLAGS=-Wall -Wextra -pedantic -std=c++11 -O3 -I../..

PROGS = BadShipping \
				BetterShipping \
				EvenBetterShipping \
				test-shipping 

all: $(PROGS)

.PHONY: clean test
clean:
		rm -f $(PROGS)

test: test-shipping
		./test-shipping

