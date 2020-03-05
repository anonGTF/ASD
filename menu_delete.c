#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head;
Node *temp;
Node *hapus;

void alokasi();
void insert_akhir();
void tampil();
void bebas();
void menu();
void del_awal();
void del_akhir();
void del_after();
void del_ini();

int main(){
    char jwb;
    do
    {
        alokasi();
        insert_akhir();
        printf("masukan data lagi? (y/n) ");
        scanf("%c", &jwb);
        fflush(stdin);
    } while (jwb == 'y' || jwb == 'Y');
    tampil();
    do
    {
        menu();
    } while (1);
    
}

void menu()
{
    int pilihan;
    printf("\nMENU DELETE\n1. Delete awal\n2. Delete akhir\n3. Delete after\n4. Delete tertentu\n5. Exit\n\n");
    printf("masukan pilihan delete: ");
    scanf("%d", &pilihan);
    switch (pilihan)
    {
    case 1:
        del_awal();
        break;
    
    case 2:
        del_akhir();
        break;

    case 3:
        del_after();
        break;

    case 4:
        del_ini();
        break;

    case 5:
        exit(0);

    default:
        printf("pilihan tidak valid\n");
        menu();
        break;
    }
    tampil();
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
    temp->next = NULL;
}

void insert_akhir()
{
    Node *tail = head;
    if (head == NULL) head = temp;
    else
    {
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = temp;
    }
}

void tampil()
{
    temp = head;
    printf("\nISI SLL\n");
    if (temp == NULL) printf("tidak ada data dalam SLL\n");    
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void bebas()
{
    free(hapus);
    hapus = NULL;
}

void del_awal()
{
    hapus = head;
    if (hapus->next == NULL) head = NULL;
    else head = hapus->next;
    bebas();    
}

void del_akhir()
{
    Node *ph = NULL;
    hapus = head;
    if (hapus->next == NULL) head = NULL;
    else
    {
        while (hapus->next != NULL)
        {
            ph = hapus;
            hapus = hapus->next;
        } 
        ph->next = NULL;   
    }
    bebas();
}

void del_after()
{
    int key;
    Node *after = head;
    printf("delete setelah: ");
    scanf("%d", &key);
    fflush(stdin);
    while (after->data != key)
    { 
        if (after->next == NULL)
        {
            printf("\n%d tidak ada dalam SLL\n", key);
            return;
        }
        after = after->next;    
    }
    hapus = after->next;
    if (hapus == NULL)
    {
        printf("tidak ada data yang dihapus");
        exit(0);
    }
    after->next = hapus->next;
    bebas();
}

void del_ini()
{
    int key;
    Node *ph = head;
    hapus = head;
    printf("delete yang mana: ");
    scanf("%d", &key);
    fflush(stdin);
    while (hapus->data != key)
    {
        if (hapus->next ==NULL)
        {
            printf("\n%d tidak ada dalam SLL\n", key);
            return;
        }
        ph = hapus;
        hapus = hapus->next;
    }
    if (head->data == key) del_awal();
    else ph->next = hapus->next;
    bebas();
}