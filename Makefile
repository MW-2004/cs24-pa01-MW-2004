CXX = g++
CFLAGS = -Wall -O2

SRCS = cards.cpp utility.cpp
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
HEADERS = $(patsubst %.cpp,%.h,$(SRCS))

all: game

cards.o: cards.cpp cards.h
	$(CXX) $(CFLAGS) -c -o $@ $<

utility.o: utility.cpp utility.h cards.h
	$(CXX) $(CFLAGS) -c -o $@ $<

main.o: main.cpp cards.h utility.h
	$(CXX) $(CFLAGS) -c -o $@ $<

test.o: test.cpp bst.h cards.h utility.h
	$(CXX) $(CFLAGS) -c -o $@ $<

test: $(OBJS) test.o
	$(CXX) $(CFLAGS) -o $@ $^

main: $(OBJS) main.o
	$(CXX) $(CFLAGS) -o $@ $^

game: $(OBJS) main.o
	$(CXX) $(CFLAGS) -o $@ $^

clean:
	del /Q *.o
	del /Q main.exe
	del /Q test.exe
	del /Q game.exe
