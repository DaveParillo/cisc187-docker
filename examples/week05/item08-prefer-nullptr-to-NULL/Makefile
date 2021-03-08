CC = clang
CXX = clang++
ifndef CXXFLAGS
	CXXFLAGS = -Wall -Wextra -pedantic -std=c++11
endif
CXXFLAGS += -Wno-unused -Wno-unused-parameter

PROGS = 01-pointer_overload \
		02-code_clarity \
		03-template_example_flat \
		04-template_example_templatized

all: $(PROGS)

clean:
	rm -f $(PROGS)


