#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAKS 256

typedef char item;
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
    Stack mystack;
    initial(&mystack);
    char masukan[MAKS];
    int stat;
    printf("masukan kata: ");
    gets(masukan);
    for (int i = 0; i < strlen(masukan); i++)
    {
        push(&mystack, masukan[i]);
    }
    for (int i = 0; i < strlen(masukan); i++)
    {
        if (pop(&mystack) != masukan[i])
        {
            stat = 0;
            break;
        }
        else
        {
            stat = 1;
        }
    }
    if (stat == 1)
    {
        printf("palindrom\n");
    }
    else
    {
        printf("bukan palindrom\n");
    }
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
