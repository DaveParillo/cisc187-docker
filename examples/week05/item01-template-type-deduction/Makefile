CXX = clang++
ifndef CXXFLAGS
	CXXFLAGS = -Wall -Wextra -pedantic -std=c++11 
endif
CXXFLAGS += -Wno-unused-parameter -Wno-unused-variable

PROGS = 01-pinch_of_pseudocode \
		02-case1_const \
		03-case1_non_const \
		04-case1_pointer \
		05-case2_uref \
		06-case3_pass_by_value \
		07-array-arguments-decay \
		08-arrays_by_value \
		10-arrays_by_reference \
		12-function-arguments

all: $(PROGS)

clean:
	rm -f $(PROGS)


