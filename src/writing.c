#include "task/task.h"
#include "utils.h"
#include "writing.h"

int csv_writer(struct single_option *opt, FILE *file)
{
    (void)file;
    if (!opt->arg)
        return -1;

    return 1;
}
