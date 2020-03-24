#include<stdio.h>
#include<stdlib.h>
#define MAKS 5

typedef int item;
typedef struct stack
{
    item data[MAKS];
    int index;
} Stack;

void initial(Stack *);
int isEmpty(Stack *);
int isFull(Stack *);
void push(Stack *, item);
item pop(Stack *);

int main(){
    char jwb;
    item mydata;
    Stack mystack;
    initial(&mystack);
    do
    {
        printf("masukan data: ");
        scanf("%d", &mydata);
        fflush(stdin);
        push(&mystack, mydata);
        printf("push lagi? (y/n) ");
        scanf("%c", &jwb);
        fflush(stdin);
    } while (jwb == 'y' || jwb == 'Y');
    printf("isi stack: \n");
    while (!isEmpty(&mystack))
    {
        printf("%d ", pop(&mystack));
    }
    return 0;
}

void initial(Stack *stack)
{
    stack->index = 0;
}

int isEmpty(Stack *stack)
{
    return (stack->index == 0) ? 1 : 0;
}

int isFull(Stack *stack)
{
    return (stack->index == MAKS) ? 1 : 0;
}

void push(Stack *stack, item data)
{
    if (isFull(stack))
    {
        printf("stack overflow!\n");
        return;
    }
    stack->data[stack->index] = data;
    stack->index++;
}

item pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("stack empty!\n");
        return NULL;
    }
    stack->index--;
    return stack->data[stack->index];
}
