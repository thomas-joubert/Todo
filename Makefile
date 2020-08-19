CC=gcc
CFLAGS= -Werror -Wall -Wextra -std=c99 -pedantic -g
LDFLAGS= -fsanitize=address
DEBUG= -g

SRC=src/main.c
OBJS=src/main.o

TARGET=todo

all : $(TARGET)

check :
	$(CXX) $(TESTFLAGS) $(TESTSRC) -o check
	./check

debug :
	$(CXX) $(DEBUG) $(SRC) -o debug

$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) $(TARGET) $(OBJS) debug check src/*.o *.o

.PHONY: clean check
