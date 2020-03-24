#include<stdio.h>
#include<stdlib.h>
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
    int dec, temp;
    char tempChar;
    Stack mystack;
    initial(&mystack);
    printf("masukan bilangan desimal: ");
    scanf("%d", &dec);
    fflush(stdin);
    if (dec == 0)
    {
        push(&mystack, 0);
    }
    while (dec != 0)
    {
        temp = dec%16;
        if (temp < 10)
        {
            tempChar = temp + '0';
        }
        else
        {
            switch (temp)
            {
            case 10:
                tempChar = 'A';
                break;
            case 11:
                tempChar = 'B';
                break;
            case 12:
                tempChar = 'C';
                break;
            case 13:
                tempChar = 'D';
                break;
            case 14:
                tempChar = 'E';
                break;
            case 15:
                tempChar = 'F';
                break;
            }
        }
        push(&mystack, tempChar);
        dec /= 16;
    }
    printf("dalam hexadesimal: ");
    while (!isEmpty(&mystack))
    {
        printf("%c", pop(&mystack));
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