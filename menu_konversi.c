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

void menu();
void dtb(int);
void dto(int);
void dtx(int);

int main(){
    while (1)
    {
        menu();
    }
    return 0;
}

void menu()
{
    int pilihan, dec;
    printf("\nmasukan angka desimal: ");
    scanf("%d", &dec);
    fflush(stdin);
    printf("\nMENU KONVERSI\n");
    printf("1.Biner\n2.Octal\n3.Hexadesimal\n4.Exit\n");
    printf("masukan pilihan kamu: ");
    scanf("%d", &pilihan);
    fflush(stdin);
    switch (pilihan)
    {
    case 1:
        dtb(dec);
        break;
    case 2:
        dto(dec);
        break;
    case 3:
        dtx(dec);
        break;
    case 4:
        exit(0);
    default:
        printf("pilihan tidak valid");
        break;
    }
}

void dtb(int dec)
{
    int temp;
    char tempChar;
    Stack mystack;
    initial(&mystack);
    if (dec == 0)
    {
        push(&mystack, '0');
    }
    while (dec != 0)
    {
        temp = dec%2;
        tempChar = temp + '0';
        push(&mystack, tempChar);
        dec /= 2;
    }
    printf("dalam biner: ");
    while (!isEmpty(&mystack))
    {
        printf("%c", pop(&mystack));
    }
}

void dto(int dec)
{
    int temp;
    char tempChar;
    Stack mystack;
    initial(&mystack);
    if (dec == 0)
    {
        push(&mystack, '0');
    }
    while (dec != 0)
    {
        temp = dec%8;
        tempChar = temp + '0';
        push(&mystack, tempChar);
        dec /= 8;
    }
    printf("dalam octal: ");
    while (!isEmpty(&mystack))
    {
        printf("%c", pop(&mystack));
    }
}

void dtx(int dec)
{
    int temp;
    char tempChar;
    Stack mystack;
    initial(&mystack);
    if (dec == 0)
    {
        push(&mystack, '0');
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
