#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MAIN_ARGS 2
#define LINE_MAX 10
#define TRUE 1
#define FALSE 0

typedef struct node
{
    int val;
    struct node *next;
} Node;

void fibo(int length, Node *head_ref);
int printFibonacci(Node *head_ref, int);
char *get_file_text(Node *head_ref);
int scan_int(int *);

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

    do
    {
        printf("Please enter fibonacci sequence length: \n");

    } while (scan_int(&fibo_length) == FALSE);

    /*
    fibo(90, &linked_list);
    printFibonacci(&linked_list, 90);

    printf("arg_count: %d\t arg_vector:%s\n", arg_count, arg_vector[1]);
        FILE *fp;
        fp = fopen("file.txt", "w+");
        fprintf(fp, get_file_text(linked_list));
        fclose(fp);
    */
    return 0;
}

int scan_int(int *num_ref)
{
    char *end;
    char buf[LINE_MAX];
    int i;

    printf("scanf %d\n", scanf("%9s", buf));
    /*
            if (!fgets(buf, sizeof buf, stdin)){
            printf("Error: your input is too long");
            return FALSE;
        }
        if(strlen(buf)<=1){
            printf("Error: your input is too short\n");
            return FALSE;
         }

    */
    for (i = 0; i < strlen(buf) - 1; i++)
    {
        if (!isdigit(buf[i]))
        {
            printf("Warning: your input is not int!!\n");
            return FALSE;
        }
    }
    *num_ref = strtol(buf, &end, 10);
    return TRUE;
    /* remove \n*/
    /*
            buf[strlen(buf) - 1] = 0;

             *num_ref = strtol(buf, &end, 10);


        if(*end == '\n'){
            printf("buf + strlen(buf): %s\n",buf + strlen(buf));
            printf("end: %s\n",end);
            printf("Info: your input is int!!\n");
    return TRUE;
        }else{
            printf("buf + strlen(buf): %s\n",buf + strlen(buf));
            printf("end: %s\n",end);
            printf("Warning: your input is not int!!\n");
    return FALSE;
        }
    */
}

/*TODO: switch derction of the list do shift instend push*/
void fibo(int length, Node *head_ref)
{
    int i, num1 = 1, num2 = 1, temp;
    Node *temp_node = head_ref;
    temp_node->val = num1;

    for (i = 1; i < length; i++)
    {
        temp_node->next = (Node *)malloc(sizeof(Node));
        temp_node = temp_node->next;
        if (i == 1)
            temp_node->val = num2;
        else
        {
            temp_node->val = num1 + num2;
            temp = num1 + num2;
            num1 = num2;
            num2 = temp;
        }
    }
    temp_node->next = head_ref;
}

char *get_file_text(Node *head_ref)
{
    char *str = (char *)malloc(sizeof(char) * 100);
    str = "Fibonacci Series in reverse order from the";
    /*  str += "term";*/
    return str;
}

int printFibonacci(Node *head_ref, int length)
{
    int count = 0, i, j;
    Node *ptr = head_ref;

    for (i = length; i != 0; i--)
    {
        for (j = 0; j < length - 1; j++)
        {
            ptr = ptr->next;
        }
        printf("%d >>> %d\n", count, ptr->val);
        count++;
    }

    return 0;
}
