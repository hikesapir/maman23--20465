#include <stdio.h>
#include <helpers.h>

int main(int arg_count, char *arg_vector[])
{
    Node linked_list;
    int fibo_length;

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

    printf("Please enter fibonacci sequence length: \n");

    fibo(90, &linked_list);
    printFibonacci(&linked_list, 90);

    printf("arg_count: %d\t arg_vector:%s\n", arg_count, arg_vector[1]);
    /*
        FILE *fp;
        fp = fopen("file.txt", "w+");
        fprintf(fp, get_file_text(linked_list));
        fclose(fp);
    */
    return 0;
}
