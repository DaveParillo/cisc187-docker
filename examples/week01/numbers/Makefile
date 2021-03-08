CXX = c++
ifndef CXXFLAGS
	CXXFLAGS = -Wall -Wextra -pedantic -std=c++11
endif

ifndef CFLAGS
	CFLAGS=-Wall -Wextra -pedantic -std=c11
endif
CFLAGS+=-Wno-unused-parameter 

PROGS = binary-print \
        float \
        float \
        mix-sign \
        overflow \
        precision \
        sizeof \
        sizes \
        zero

all: $(PROGS)

clean:
		rm -f $(PROGS)


