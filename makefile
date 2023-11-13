CXX = g++
CFLAGS = -Wall -O2

SRCS = cards.cpp utility.cpp bst.cpp
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
HEADERS = $(patsubst %.cpp,%.h,$(SRCS))

all: test main

cards.o: cards.cpp cards.h
	$(CXX) $(CFLAGS) -c -o $@ $<

utility.o: utility.cpp utility.h cards.h
	$(CXX) $(CFLAGS) -c -o $@ $<

bst.o: bst.cpp bst.h cards.h utility.h
	$(CXX) $(CFLAGS) -c -o $@ $<

main.o: main.cpp bst.h cards.h utility.h
	$(CXX) $(CFLAGS) -c -o $@ $<

test.o: test.cpp bst.h cards.h utility.h
	$(CXX) $(CFLAGS) -c -o $@ $<

test: $(OBJS) test.o
	$(CXX) $(CFLAGS) -o $@.exe $^

main: $(OBJS) main.o
	$(CXX) $(CFLAGS) -o $@.exe $^

clean:
	del /Q *.o
	del /Q main.exe
	del /Q test.exe
