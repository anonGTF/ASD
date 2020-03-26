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
int derajat(char);
void konversi(char[MAKS]);

int main(){
    char jwb;
    do
    {
        char infix[MAKS];
        printf("\nmasukan notasi infix: ");
        gets(infix);
        fflush(stdin);
        printf("dalam postfix: ");
        konversi(infix);
        printf("\nmau lagi? (y/n) ");
        scanf("%c", &jwb);
        fflush(stdin);
    } while (jwb == 'y' || jwb == 'Y');
    return 0;
}

void konversi(char infix[MAKS])
{ 
    Stack mystack;
    initial(&mystack);
    char temp;
    int drjt;
    for (int i = 0; i < strlen(infix); i++)
    {
        if (infix[i] > '0' && infix[i] <= '9')
        {
            printf("%c ", infix[i]);
        }
        else if ( infix[i] == '(')
        {
            push(&mystack, infix[i]);
        }
        else if (infix[i] == ')')
        {
            push(&mystack, infix[i]);
            temp = " ";
            while (temp != '(')
            {
                temp = pop(&mystack);
                if (temp == '(' || temp == ')')
                {
                    continue;
                }
                printf("%c ", temp);
            }
        }
        else
        {
            drjt = derajat(infix[i]);
            if (isEmpty(&mystack) || drjt > derajat(mystack.data[mystack.index]))
            {
                push(&mystack, infix[i]);
            }
            else
            {
                while (drjt < derajat(mystack.data[mystack.index]))
                {
                    temp = pop(&mystack);
                    printf("%c ", temp);
                }
                push(&mystack, infix[i]);
            }
        }
    }
    while (!isEmpty(&mystack))
    {
        printf("%c ", pop(&mystack));
    }
}

int derajat(char op)
{
    switch (op)
    {
    case '(':
        return 0;
        break;
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '^':
        return 3;
        break;
    default:
        return -1;
        break;
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
