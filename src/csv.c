#include "task/task.h"
#include "utils.h"
#include "csv.h"

int get_number_of_tasks(FILE *file)
{
    char *line = NULL;
    size_t size = 0;

    int lines = -1;

    while(getline(&line, &size, file) != -1)
        lines++;

    return lines;
}

int csv_writer(struct single_option *opt, FILE *file)
{
    int number = get_number_of_tasks(file) + 1;

    if (!opt->task)
        return -1;

    fprintf(file, "%d,%s,%s", number, opt->task, "None");

    fclose(file);

    return 1;
}
