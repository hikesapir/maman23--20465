#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "helpers.h"

/*
Makes a circular linked list of the first N terms in fibonacci sequence
return TRUE(1) if fibonacci sequence created successfully
return FALSE(0) if has an issues

@param **head_ref - reference to the head of fibonacci sequence list
@param length - the number of terms
*/
int fibo(Node **head_ref, int length)
{
    int i, num1 = 1, num2 = 1, temp;
    Node *temp_node, *first_node;

    for (i = 0; i <= length; i++)
    {
        temp_node = (Node *)malloc(sizeof(Node));
        if (temp_node == NULL)
        {
            printf("Error: no space \n");
            return FALSE;
        }
        /* the first value */
        if (i == 0)
        {
            temp_node->val = num1;
            first_node = temp_node;
        }
        /* the second value */
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

    /* makes the list circular */
    first_node->next = *head_ref;
    printf("Info: fibonacci sequence created successfully\n");
    return TRUE;
}

/*
Prints the fibonacci sequence in reverse order

@param *head_ref - reference to the head of fibonacci sequence list
@param length - the number of terms
*/
void print_fibonacci(Node *head_ref, int length)
{
    int i;
    Node *ptr = head_ref;

    printf("The %d terms of fibonacci series in reverse order.\n", length);
    for (i = length; i >= 0; i--)
    {
        printf("%d >>> %d\n", i, ptr->val);
        ptr = ptr->next;
    }
}

/*
Creates file and prints the fibonacci sequence in reverse order

@param *file_name - the file name
@param **head_ref - reference to the head of fibonacci sequence list
@param length - the number of terms
*/
void make_fibo_file(char *file_name, Node *fibo_list, int length)
{
    FILE *fp;
    int i;
    Node *ptr = fibo_list;

    fp = fopen(file_name, "w");
    if (fp == NULL)
    {
        printf("Error: can not create the file %s\n", file_name);
        return;
    }

    fprintf(fp, "The %d terms of fibonacci series in reverse order:\n", length);

    for (i = length; i >= 0; i--)
    {
        fprintf(fp, "%d >>> %d\n", i, ptr->val);
        ptr = ptr->next;
    }

    printf("Info: the file %s created successfully\n", file_name);
}

/*
Reads an integer from the user
return TRUE(1) if read an integer successfully
return FALSE(0) if has an issues

@param *num_ref - reference to int variable
*/
int scan_int(int *num_ref)
{
    char *str;
    char c;
    int i = 0, line_size = 0;

    line_size = ENLARGE_LINE_SIZE(line_size);
    str = (char *)malloc(line_size * sizeof(char));
    if (str == NULL)
    {
        printf("Error: no space \n");
        return FALSE;
    }

    /* reads the user input */
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (i == line_size)
        {
            line_size = ENLARGE_LINE_SIZE(line_size);
            STR_REALLOC(str, line_size);
        }
        str[i] = c;
        i++;
    }
    str[i] = '\0';
    printf("Info: received %s\n", str);
    if (i < MIN_LENGTH)
    {
        printf("Warning: your input is too short\n");
        return FALSE;
    }
    /* chacks if the user input is an integer */
    for (i = 0; i < strlen(str); i++)
    {
        if (!isdigit(str[i]))
        {
            printf("Warning: your input is not a number!!\n");
            free(str);
            return FALSE;
        }
    }

    *num_ref = strtol(str, NULL, 10);

    free(str);
    return TRUE;
}

/*
Release the allocated memory of a linked list

@param *head_ref - reference to the head of list
*/
void free_linked_list(Node *head_ref, int length)
{
    Node *tmp;

    while (length >= 0)
    {
        tmp = head_ref;
        head_ref = head_ref->next;
        free(tmp);
        length--;
    }

    printf("Info: safely release the allocated memory\n");
}
