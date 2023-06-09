#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <helpers.h>

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

int scan_int()
{
    char *str;
    char c;
    int i = 0, n = 0, line_size = 0;

    line_size = ENLARGE_LINE_SIZE(line_size);
    str = (char *)malloc(line_size * sizeof(char));
    if (str == NULL)
        return -1;

    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (i == LINE_MAX)
        {
            line_size = ENLARGE_LINE_SIZE(line_size);
            CHAR_REALLOC(str, line_size);
        }
        str[i] = c;
        i++;
    }
    str[i] = '\0';

    printf("length: %d\n", strlen(str));
    for (i = 0; i < strlen(str); i++)
    {
        if (!isdigit(str[i]))
        {
            printf("Warning: your input is not int!!\n");
            free(str);
            return FALSE;
        }
    }

    n = strtol(str, NULL, 10);

    printf("your num is: %d\n", n);
    free(str);
    return TRUE;
}

/*void scan_int()
{
    char *end;
    char buf[LINE_MAX];
    int n;
    do
    {
        if (!fgets(buf, sizeof buf, stdin))
            break;
        printf("your input is: %s\n", buf);

        buf[strlen(buf) - 1] = 0;

        n = strtol(buf, &end, 10);
    } while (end != buf + strlen(buf));
    printf("your num is: %d\n", n);
}*/