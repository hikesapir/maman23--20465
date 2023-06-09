#define MAX_MAIN_ARGS 2
#define MIN_LENGTH 1
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

int scan_int(int *num_ref);
void fibo(Node **head_ref, int length );
void printFibonacci(Node *head_ref, int length);
void make_fibo_file(char *file_name, Node *fibo_list, int length);