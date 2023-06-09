#define MAX_MAIN_ARGS 2
#define LINE_MAX 100
#define TRUE 1
#define FALSE 0
#define ENLARGE_LINE_SIZE(SIZE) (SIZE) + 20
#define CHAR_REALLOC(PTR, SIZE)                            \
    (PTR) = (char *)realloc((PTR), (SIZE) * sizeof(char)); \
    if ((PTR) == NULL)                                     \
    {                                                      \
        printf("No space\n");                              \
        return -1;                                         \
    }

typedef struct node
{
    int val;
    struct node *next;
} Node;



void fibo(int length, Node *head_ref);
int printFibonacci(Node *head_ref, int);
char *get_file_text(Node *head_ref);
int scan_int();