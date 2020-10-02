#include <criterion/criterion.h>
#include <stdlib.h>
#include <err.h>

#include "../src/writing.h"
#include "../src/utils.h"

//Since the size of a char = 1 byte, a file's size amounts to its number of char
int file_size(FILE *file)
{
    fseek(file, 0, SEEK_END);
    return ftell(file);
}

Test(csv_writer, empty_arg)
{
    FILE *file = fopen("tests.csv", "w+");

    if (file == NULL)
        err(-3, "Error during file opening\n");

    struct single_option opt =
    {
        ADD, NULL
    };

    int file_state_b = file_size(file);
    int ret = csv_writer(&opt, file);
    int file_state_a = file_size(file);

    cr_assert_eq(ret, -1, "Bad return value, should have returned -1, \
            returned %d", ret);
    cr_assert_eq(file_state_b, file_state_a, "The file has been modified by %d\
            characters", file_state_a - file_state_b);
}
