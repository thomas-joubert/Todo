CC=gcc
CFLAGS= -Werror -Wall -Wextra -std=c99 -pedantic -g -D_POSIX_C_SOURCE=200809L
LDFLAGS= -fsanitize=address
TESTFLAGS= -lcriterion -DDEF_TESTS
DEBUG= -g

SRC=src/main.c src/task/task.c src/linked_tasks.c src/utils.c src/writing.c
OBJS= $(SRC:.c=.o)
TESTSRC=tests/opt-parser.c src/utils.c src/writing.c tests/csv_writer.c

TARGET=todo

all : $(TARGET)

check :
	$(CC) $(CFLAGS) $(TESTFLAGS) $(TESTSRC) -o check
	./check
	rm check

debug :
	$(CC) $(DEBUG) $(SRC) -o debug

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	$(RM) $(TARGET) $(OBJS) debug check src/*.o *.o

.PHONY: clean check
