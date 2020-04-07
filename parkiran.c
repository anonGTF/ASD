#include<stdio.h>
#include<stdlib.h>
#define MAKS 5

typedef int item;
typedef struct
{
    int count, front, rear;
    item data[MAKS];
}Queue;
typedef struct stack
{
    item data[MAKS];
    int index;
} Stack;

int NO_PARKIR = 1;

void initial(Queue *);
int isEmpty(Queue *);
int isFull(Queue *);
void enqueue(Queue *, item);
item dequeue(Queue *);
void tampil(Queue *);
item keluar(item, Queue *, Stack *);
void initial_stack(Stack *);
int isEmpty_stack(Stack *);
int isFull_stack(Stack *);
void push(Stack *, item);
item pop(Stack *);
void menu(Queue *, Stack *);

int main(){
    Queue mine;
    initial(&mine);
    Stack stack;
    initial_stack(&stack);
    while (1)
    {
        menu(&mine, &stack);
    }
    // menu();
    return 0;
}

void menu(Queue *q, Stack *s)
{
    int jwb, no;
    printf("\n\nMENU PARKIR\n");
    printf("1. parkir mobil\n2. keluarkan mobil\n3. exit\n");
    printf("masukan pilihan: ");
    scanf("%d", &jwb);
    fflush(stdin);
    switch (jwb)
    {
        case 1:
            printf("mobil masuk no-%d\n", NO_PARKIR);
            enqueue(q, NO_PARKIR);
            NO_PARKIR++;
            tampil(q);
            break;
        case 2:
            printf("mana yg dikeluarkan: ");
            scanf("%d", &no);
            fflush(stdin);
            printf("mobil keluar : %d\n", keluar(no, q, s));
            tampil(q);
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("masukan invalid!\n");
            break;
    }
}

item keluar(item no, Queue *q, Stack *s)
{
    int try, temp;
    try = dequeue(q);
    while (try != no)
    {
        push(s, try);
        try = dequeue(q);
    }
    while (!isEmpty_stack(s))
    {
        temp = pop(s);
        q->front = (q->front - 1) % MAKS;
        q->data[q->front] = temp;
        q->count++;
    }
    return no;
}

void tampil(Queue *q)
{
    printf("\nISI PARKIRAN: \n");
    if (isEmpty(q))
    {
        printf("parkiran kosong");
        return;
    }
    else if (q->front < q->rear)
    {   
        for (int i = q->front; i < q->rear; i++)
        {
            printf("%d ", q->data[i]);
        }
    }
    else if (q->front >= q->rear)
    {
        for (int i = q->front; i < MAKS; i++)
        {
            printf("%d ", q->data[i]);
        }
        for (int i = 0; i < q->rear; i++)
        {
            printf("%d ", q->data[i]);
        }
    }
    
    
}

void initial(Queue *q)
{
    q->count = 0;
    q->front = 0;
    q->rear = 0;
}

int isEmpty(Queue *q)
{
    return (q->count == 0) ? 1 : 0;
}

int isFull(Queue *q)
{
    return (q->count == MAKS) ? 1: 0;
}

void enqueue(Queue *q, item data)
{
    if (isFull(q))
    {
        printf("Parkir penuh! gaboleh masuk!\n");
        return;
    }
    q->data[q->rear] = data;
    q->rear = (q->rear + 1) % MAKS;
    q->count++;
}

item dequeue (Queue *q)
{
    item temp;
    if (isEmpty(q))
    {
        printf("queue kosong!\n");
        return NULL;
    }
    temp = q->data[q->front];
    q->front = (q->front + 1) % MAKS;
    q->count--;
    return temp;
}

void initial_stack(Stack *stack)
{
    stack->index = 0;
}

int isEmpty_stack(Stack *stack)
{
    return (stack->index == 0) ? 1 : 0;
}

int isFull_stack(Stack *stack)
{
    return (stack->index == MAKS) ? 1 : 0;
}

void push(Stack *stack, item data)
{
    if (isFull_stack(stack))
    {
        printf("stack overflow!\n");
        return;
    }
    stack->data[stack->index] = data;
    stack->index++;
}

item pop(Stack *stack)
{
    if (isEmpty_stack(stack))
    {
        printf("stack empty!\n");
        return NULL;
    }
    stack->index--;
    return stack->data[stack->index];
}
