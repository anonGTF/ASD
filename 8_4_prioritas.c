#include<stdio.h>
#include<stdlib.h>

typedef int item;
typedef struct node
{
    item data;
    int prior;
    struct node *next;
} Node;

Node *front = NULL;
Node *temp = NULL;
Node *hapus = NULL;
Node *rear = NULL;

void alokasi();
void enqueue();
item dequeue();
void bebas();
void tampil();
void menu();

int main(){
    while (1)
    {
        menu();
    }
}

void menu()
{
    int jwb;
    char data;
    printf("\nmenu queue\n");
    printf("1.masukan data\n2.ambil data\n3.exit\n");
    printf("masukan pilihan: ");
    scanf("%d", &jwb);
    fflush(stdin);
    switch (jwb)
    {
    case 1:
        enqueue();
        tampil();
        break;
    case 2:
        printf("\ndata yg diambil: %d\n", dequeue());
        tampil();
        break;
    case 3:
        exit(0);
    default:
        printf("tidak valid!\n");
        break;
    }
}

void alokasi()
{
    temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("malloc gagal");
        exit(0);
    }
    printf("masukan data: ");
    scanf("%d", &temp->data);
    fflush(stdin);
    printf("masukan prioritas (1/2/3/4/5) : ");
    scanf("%d", &temp->prior);
    fflush(stdin);
    temp->next = NULL;
}

void enqueue()
{
    Node *pos = front;
    Node *bef_pos;
    alokasi();
    if (front == NULL) 
    {
        front = temp;
        rear = front;
    }
    else if (temp->prior < front->prior)
    {
        temp->next = front;
        front = temp;
    }
    else if (temp->prior > rear->prior)
    {
        rear->next = temp;
        rear = temp;
    }
    else
    {
        while (pos->prior <= temp->prior)
        {
            bef_pos = pos;
            if (pos->next == NULL)
            {
                break;
            }
            pos = pos->next;
        }
        if (bef_pos->next == NULL)
        {
            bef_pos->next = temp;
            rear = temp;
        }
        else
        {
            temp->next = pos;
            bef_pos->next = temp;
        }
    }
}

item dequeue()
{
    hapus = front;
    if (hapus == NULL)
    {
        printf("QUEUE KOSONG!");
        return '\0';
    }
    item temp = hapus->data;
    if (hapus->next == NULL) front = NULL;
    else front = hapus->next;
    bebas();  
    return temp;
}

void tampil()
{
    Node *show = front;
    printf("\nISI QUEUE\n");  
    if (show == NULL)
    {
        printf("QUEUE KOSONG!\n");
        return;
    }
    printf("data\tprior\n");
    while (show != NULL)
    {
        printf("%d\t%d\n", show->data, show->prior);
        show = show->next;
    }
}

void bebas()
{
    free(hapus);
    hapus = NULL;
}