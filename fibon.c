#include <stdio.h>
#include "helpers.h"

int main(int arg_count, char *arg_vector[])
{
    int fibo_length;
    Node *fibo_list;

    /* validate the mount of arguments */
    if (arg_count < MAX_MAIN_ARGS)
    {
        printf("Error: missing file name\n");
        return 1;
    }
    else if (arg_count > MAX_MAIN_ARGS)
    {
        printf("Error: too many arguments\n");
        return 1;
    }

    /* getting the sequence length */
    do
    {
        printf("Please enter fibonacci sequence length: \n");

    } while (scan_int(&fibo_length) == FALSE);

    /* make fibonacci series */
    fibo(&fibo_list, fibo_length);
    /* print the fibonacci series */
    print_fibonacci(fibo_list, fibo_length);
    /* print to the fibonacci series */
    make_fibo_file(arg_vector[1], fibo_list, fibo_length);
    /* release the allocated memory */
    free_linked_list(fibo_list);
    return 0;
}