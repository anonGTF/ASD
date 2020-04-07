#include<stdio.h>
#include<stdlib.h>

typedef char item;
typedef struct node
{
    item data;
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
    printf("1.enqueue\n2.dequeue\n3.lihat isi\n4.exit\n");
    printf("masukan pilihan: ");
    scanf("%d", &jwb);
    fflush(stdin);
    switch (jwb)
    {
    case 1:
        enqueue();
        break;
    case 2:
        printf("\ndata yg diambil: %c\n", dequeue());
        break;
    case 3:
        tampil();
        break;
    case 4:
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
    scanf("%c", &temp->data);
    fflush(stdin);
    temp->next = NULL;
}

void enqueue()
{
    alokasi();
    if (front == NULL) 
    {
        front = temp;
        rear = front;
    }
    else
    {
        rear->next = temp;
        rear = rear->next;
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
        printf("QUEUE KOSONG!");
    }
    while (show != NULL)
    {
        printf("%c\n", show->data);
        show = show->next;
    }
}

void bebas()
{
    free(hapus);
    hapus = NULL;
}
