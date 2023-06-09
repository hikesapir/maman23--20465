#define MAX_MAIN_ARGS 2
#define MIN_LENGTH 1
#define TRUE 1
#define FALSE 0
#define ENLARGE_LINE_SIZE(SIZE) (SIZE) + 20
#define STR_REALLOC(PTR, SIZE)                             \
    (PTR) = (char *)realloc((PTR), (SIZE) * sizeof(char)); \
    if ((PTR) == NULL)                                     \
    {                                                      \
        printf("Error: no space \n");                      \
        return FALSE;                                      \
    }

typedef struct node
{
    int val;
    struct node *next;
} Node;

/*
Reads an integer from the user
return TRUE(1) if read an integer successfully
return FALSE(0) if has an issues

@param *num_ref - reference to int variable
*/
int scan_int(int *num_ref);

/*
Makes a circular linked list of the first N terms in fibonacci sequence
return TRUE(1) if fibonacci sequence created successfully
return FALSE(0) if has an issues

@param **head_ref - reference to the head of fibonacci sequence list
@param length - the number of terms
*/
int fibo(Node **head_ref, int length);

/*
Prints the fibonacci sequence in reverse order

@param *head_ref - reference to the head of fibonacci sequence list
@param length - the number of terms
*/
void print_fibonacci(Node *head_ref, int length);

/*
Creates file and prints the fibonacci sequence in reverse order

@param *file_name - the file name
@param **head_ref - reference to the head of fibonacci sequence list
@param length - the number of terms
*/
void make_fibo_file(char *file_name, Node *fibo_list, int length);

/*
Release the allocated memory of a linked list

@param *head_ref - reference to the head of list
@param length - the list length
*/
void free_linked_list(Node *head_ref, int length);