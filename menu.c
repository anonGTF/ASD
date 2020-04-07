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
void menu(Queue *);
void intip(Queue *);

int main(){
    Queue mine;
    initial(&mine);
    while (1)
    {
        menu(&mine);
    }
}

void menu(Queue *q)
{
    int jwb;
    char data;
    printf("\nmenu queue\n");
    printf("1.enqueue\n2.dequeue\n3.lihat isi\n4.exit\n");
    printf("masukan pilihan: ");
    scanf("%d", &jwb);
    fflush(stdin);
    switch (jwb)
    {
    case 1:
        printf("masukan data: ");
        scanf("%c", &data);
        fflush(stdin);
        enqueue(q, data);
        break;
    case 2:
        printf("\ndata yg diambil: %c\n", dequeue(q));
        break;
    case 3:
        intip(q);
        break;
    case 4:
        exit(0);
    default:
        printf("tidak valid!\n");
        break;
    }
}

void intip(Queue *q)
{
    printf("\nISI QUEUE: ");
    if (q->count == 0)
    {
        printf("QUEUE KOSONG!\n");
        return;
    }
    for (int i = 0; i < q->count; i++)
    {
        printf("%c ", q->data[i]);
    }
    printf("\n");
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
