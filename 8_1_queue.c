#include<stdio.h>
#include<stdlib.h>
#define MAKS 5

typedef char item;
typedef struct
{
    int count, front, rear;
    item data[MAKS];
}Queue;

void initial(Queue *);
int isEmpty(Queue *);
int isFull(Queue *);
void enqueue(Queue *, item);
item dequeue(Queue *);

int main(){
    char jwb, data;
    Queue mine;
    initial(&mine);
    do
    {
        printf("masukan data: ");
        scanf("%c", &data);
        fflush(stdin);
        enqueue(&mine, data);
        printf("masukan lagi? (y/n) ");
        scanf("%c", &jwb);
        fflush(stdin);
    } while (jwb == 'y' || jwb == 'Y');
    printf("\nISI QUEUE\n");
    while (isEmpty(&mine) == 0)
    {
        printf("%c\n", dequeue(&mine));
    }
    return 0;
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
        printf("queue penuh!\n");
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