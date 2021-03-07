#ifndef DEF_WRITING
#define DEF_WRITING

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

/* Format of the csv file :
 * id,name,description
 */

// Take a task as option (add), and write the corresponding task into a csv file
int csv_writer(struct single_option *opt, FILE *file);

// Get the number of tasks currently in the file
int get_number_of_tasks(FILE *file);

#endif
