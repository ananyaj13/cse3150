CC=g++
CFLAGS= -c -std=c++17 -Wall
LFLAGS= -g
OFILES=   myfind_main.o myfind.o unit_texts_find.o
#All the .o's file that are going to be created ADD in all the .o's that are needed to

OMAIN_FILES = myfind_main.o myfind.o 
all: main

OUNIT_TEST_FILES = unit_tests_find.o myfind.o 
all: myfind_tests

main: $(OMAIN_FILES) # the main final executable  which takes all the ofiles and build the executable to run
	$(CC) $(LFLAGS) $(OMAIN_FILES) -o myfind_main

myfind_tests: $(OUNIT_TEST_FILES) # the main final executable  which takes all the ofiles and build the executable to run
	$(CC) $(LFLAGS) $(OUNIT_TEST_FILES) -o myfind_unit_tests


# the main function .. this contains all the functionality/unittest test that are to be run

myfind_main.o : myfind.cpp myfind_main.cpp

myfind.o : myfind.cpp

unit_tests_find.o : myfind.cpp unit_tests_find.cpp


# hardcode the final executable name which is given in the `all` above
clean: 
	rm -rf *.o  a.out