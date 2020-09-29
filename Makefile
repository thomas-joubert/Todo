CC=gcc
CFLAGS= -Werror -Wall -Wextra -std=c99 -pedantic -g -D_POSIX_C_SOURCE=200809L
LDFLAGS= -fsanitize=address
TESTFLAGS= -lcriterion -DDEF_TESTS
DEBUG= -g

SRC=src/main.c src/task/task.c src/linked_tasks.c src/utils.c
OBJS=src/main.o src/task/task.o src/linked_tasks.o src/utils.o
TESTSRC=tests/opt-parser.c src/utils.c

TARGET=todo

all : $(TARGET)

check :
	$(CC) $(CFLAGS) $(TESTFLAGS) $(TESTSRC) -o check
	./check

debug :
	$(CC) $(DEBUG) $(SRC) -o debug

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	$(RM) $(TARGET) $(OBJS) debug check src/*.o *.o

.PHONY: clean check
