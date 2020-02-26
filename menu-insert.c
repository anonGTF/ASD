#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head = NULL;
Node *temp = NULL;

void alokasi();
void insert_awal();
void insert_akhir();
void insert_after();
void insert_before();
void tampil();
void menu();

int main(){
    do
    {
        menu();
    } while (1);
    return 0;
}

void menu()
{
    int pilihan;
    printf("\nMENU INSERT:\n1.awal\n2.akhir\n3.after\n4.before\n5.exit\n");
    printf("masukan pilihan: ");
    scanf("%d", &pilihan);
    fflush(stdin);
    if (pilihan < 1 || pilihan >5)
    {
        printf("pilihan tidak ada dalam menu\n");
        menu();
    }
    else if (head == NULL && (pilihan == 3 || pilihan == 4))
    {
        printf("masukan pertama tidak boleh insert after atauinsert before\n");
        menu();
    }
    else
    {
        alokasi();
        switch (pilihan)
        {
        case 1:
            insert_awal();
            break;
        case 2:
            insert_akhir();
            break;
        case 3:
            insert_after();
            break;
        case 4:
            insert_before();
            break;
        case 5:
            exit(0);
        }
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

void insert_awal()
{
    if (head != NULL)
    {
        temp->next = head;
    }
    head = temp;
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

void insert_after()
{
    int key;
    Node *after = head;
    printf("masukan setelah: ");
    scanf("%d", &key);
    while (after->data != key)
    {
        if (after->next == NULL)
        {
            printf("%d tidak ada dalam SLL", key);
            exit(0);
        }
        after = after->next;
    }
    temp->next = after->next;
    after->next = temp;
}

void insert_before()
{
    int key;
    Node *pbefore = head;
    Node *pkey = head;
    printf("masukan sebelum: ");
    scanf("%d", &key);
    fflush(stdin);
    if (head->data == key) insert_awal();
    else
    {
        while (pkey->data != key)
        {
            if (pkey->next == NULL)
            {
                printf("%d tidak ada dalam SLL", key);
                exit(0);
            }
            pbefore = pkey;
            pkey = pkey->next;
        }   
        temp->next = pkey;
        pbefore->next = temp;
    }
}

void tampil()
{
    printf("\nISI SLL: \n");
    temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
