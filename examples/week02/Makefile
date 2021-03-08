CC = clang
CXX = clang++
ifndef CXXFLAGS
	CXXFLAGS = -Wall -Wextra -pedantic -std=c++14
endif
ifndef CFLAGS
	CFLAGS = -Wall -Wextra -pedantic -std=c11
endif

CXXFLAGS+=-I..

PROGS = strings \
		strings_c \
		vectors \
		vector-api

all: $(PROGS)

clean:
	rm -f $(PROGS)

