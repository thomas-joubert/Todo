#ifndef DEF_WRITING
#define DEF_WRITING

#include <stdio.h>

#include "utils.h"

// Take a task an option (add), and write the corresponding task into a csv file
int csv_writer(struct single_option *opt, FILE *file);

#endif
