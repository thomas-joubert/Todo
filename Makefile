CC=gcc
CFLAGS= -Werror -Wall -Wextra -std=c99 -pedantic -g -D_POSIX_C_SOURCE=200809L
LDFLAGS= -fsanitize=address
DEBUG= -g

SRC=src/main.c src/task/task.c src/linked_tasks.c src/utils.c
OBJS=src/main.o src/task/task.o src/linked_tasks.o src/utils.o

TARGET=todo

all : $(TARGET)

check :
	$(CXX) $(TESTFLAGS) $(TESTSRC) -o check
	./check

debug :
	$(CXX) $(DEBUG) $(SRC) -o debug

$(TARGET) : $(OBJS)
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	$(RM) $(TARGET) $(OBJS) debug check src/*.o *.o

.PHONY: clean check
