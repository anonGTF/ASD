#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head = NULL;
Node *temp = NULL;

void insert_awal();
void insert_akhir();
void insert_after();
void insert_before();
void alokasi();
void tampil();

int main(){
    char jwb;
    do
    {
        alokasi();
        insert_akhir();
        printf("tambah lagi? (y/n) ");
        scanf("%c", &jwb);
    } while (jwb == 'y' || jwb == 'Y');
    tampil();
    return 0;
}

void insert_awal(){
    if (head != NULL) temp->next = head;
    head = temp;
}

void insert_akhir(){
    Node *tail = NULL;
    if (head == NULL) head = temp;
    else
    {
        tail = head;
        while (tail->next!=NULL)
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
    fflush(stdin);
    while (after->data != key)
    {
        if (after->next == NULL)
        {
            printf("%d tidak ada pada SLL", key);
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
    if (head->data == key) insert_awal();
    else
    {
    temp->next = pkey;
    pbefore->next = temp;
    }
}

void alokasi(){
    temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("malloc gagal");
        exit(0);
    }
    printf("masukan angka: ");
    scanf("%d", &temp->data);
    fflush(stdin);
    temp->next = NULL;
}

void tampil()
{
    Node *temp = head;
    do
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    } while (temp != NULL);
}
