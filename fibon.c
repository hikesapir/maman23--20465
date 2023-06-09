#include <stdio.h>
#include "helpers.h"

int main(int arg_count, char *arg_vector[])
{
    int fibo_length;
	 Node *linked_list;

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


    do
    {
        printf("Please enter fibonacci sequence length: \n");

    } while (scan_int(&fibo_length) == FALSE);

    printf("fibo_length: %d\n",fibo_length);

	fibo(&linked_list, fibo_length);
	printFibonacci(linked_list, fibo_length);
	make_fibo_file(arg_vector[1], linked_list, fibo_length);

    return 0;
}