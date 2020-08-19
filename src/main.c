#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        //show_list()
        puts("fine");
    }
    else
    {
        printf("%d\n", argc);
        printf("%s\n", argv[0]);
        puts("Not fine");
    }

    return 0;
}
