CXX = c++
CXXFLAGS+= -I../..

all: hello test

hello: clean
	${CXX} ${CXXFLAGS} -o $@ Hello.cpp main.cpp

.PHONY: clean test
clean: 
	rm -f test hello *.o


test: clean
	${CXX} ${CXXFLAGS} -o $@ Hello.cpp test-hello.cpp
	./test


