#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "helpers.h"

void fibo(Node **head_ref, int length)
{

    int i, num1 = 1, num2 = 1, temp;
    Node *temp_node, *first_node;

    if (length < MIN_LENGTH)
        return;

    for (i = 0; i < length; i++)
    {
        temp_node = (Node *)malloc(sizeof(Node));
        if (i == 0)
        {
            temp_node->val = num1;
            first_node = temp_node;
        }
        else if (i == 1)
            temp_node->val = num2;
        else
        {
            temp_node->val = num1 + num2;
            temp = num1 + num2;
            num1 = num2;
            num2 = temp;
        }
        temp_node->next = *head_ref;
        *head_ref = temp_node;
    }

    first_node->next = *head_ref;
}

void printFibonacci(Node *head_ref, int length)
{
    int count = 0, i;
    Node *ptr = head_ref;

    for (i = length; i != 0; i--)
    {
        printf("%d >>> %d\n", count, ptr->val);
        ptr = ptr->next;
        count++;
    }
}

void make_fibo_file(char *file_name, Node *fibo_list, int length)
{
    FILE *fp;
    int i;
    Node *ptr = fibo_list;

    fp = fopen(file_name, "w");

    fprintf(fp, "The %d terms of fibonacci series in reverse order.\n", length);

    for (i = length; i != 0; i--)
    {
        fprintf(fp, "%d\n", ptr->val);
        ptr = ptr->next;
    }
}

int scan_int(int *num_ref)
{
    char *str;
    char c;
    int i = 0, line_size = 0;

    line_size = ENLARGE_LINE_SIZE(line_size);
    str = (char *)malloc(line_size * sizeof(char));
    if (str == NULL)
        return -1;

    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (i == line_size)
        {
            line_size = ENLARGE_LINE_SIZE(line_size);
            CHAR_REALLOC(str, line_size);
        }
        str[i] = c;
        i++;
    }
    str[i] = '\0';
    if (i < MIN_LENGTH)
    {
        printf("too short\n");
        return FALSE;
    }
    for (i = 0; i < strlen(str); i++)
    {
        if (!isdigit(str[i]))
        {
            printf("Warning: your input is not int!!\n");
            free(str);
            return FALSE;
        }
    }

    *num_ref = strtol(str, NULL, 10);

    free(str);
    return TRUE;
}
