CC=gcc
CFLAGS= -Werror -Wall -Wextra -std=c99 -pedantic -g
LDFLAGS= -fsanitize=address
DEBUG= -g

SRC=src/main.c src/task.c src/linked_tasks.c
OBJS=src/main.o src/task.o src/linked_tasks.o

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
