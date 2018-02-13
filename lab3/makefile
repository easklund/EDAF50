# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC  = $(CXX)

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU's libstdc++.
# -g is for debugging.
CPPFLAGS =  -std=c++11 -I.
CXXFLAGS =  -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast
CXXFLAGS += -std=c++11
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g
#CPPFLAGS += -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS +=  -stdlib=libc++

# Targets
PROGS =  test_tag_remover date_test prime_test to_string

all: $(PROGS)

tagtest: test_tag_remover
	./test_tag_remover

datetest: date_test
	./date_test

primetest: prime_test
	./prime_test

tostringtest: to_string
	./to_string

#datetest: date_test
#	./date_test

# Targets rely on implicit rules for compiling and linking
test_tag_remover: tagRemover.o test_tag_remover.o
date_test: date_test.o date.o
prime_test: prime_test.o prime.o
to_string: to_string.o date.o

#pre: pre.o
#spell: dictionary.o word.o spell.o

# Phony targets
.PHONY: all test clean distclean

# Standard clean
clean:
	rm -f *.o $(PROGS)

distclean: clean
	rm *.d


# Include the *.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
