CC = clang
CXX = clang++
ifndef CXXFLAGS
	CXXFLAGS = -Wall -Wextra -pedantic -std=c++11
endif
ifndef CFLAGS
	CFLAGS = -Wall -Wextra -pedantic -std=c11
endif
CFLAGS += -Wno-unused-parameter

PROGS = 01-pointers-and-references \
		02-array-copy \
		01a-point-to-pointer \
		03-string-pointers

all: $(PROGS)

clean:
	rm -f $(PROGS)

