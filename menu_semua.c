#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head = NULL;
Node *temp = NULL;
Node *hapus = NULL;

void alokasi();
void insert_awal();
void insert_akhir();
void insert_after();
void insert_before();
void del_awal();
void del_akhir();
void del_after();
void del_ini();
void bebas();
void tampil();
void menu_insert();
void menu_delete();
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
    printf("\nMenu Utama:\n1. Insert\n2. Delete\n3. Exit\n");
    printf("masukan pilihan Anda: ");
    scanf("%d", &pilihan);
    fflush(stdin);
    if (head == NULL && pilihan == 2)
    {
        printf("\nbelum ada data nih.. insert dulu yuk! \n\n");
        return;
    }
    else if (pilihan == 1)
    {
        menu_insert();
    }
    else if (pilihan == 2)
    {
        menu_delete();
    }
    else if (pilihan == 3)
    {
        exit(0);
    }
    else
    {
        printf("\nhmm.. kayaknya kamu salah ketik deh. Coba lagi yuk! \n");
        return;
    }
}

void menu_insert()
{
    int pilihan;
    printf("\nMENU INSERT:\n1.awal\n2.akhir\n3.after\n4.before\n");
    printf("masukan pilihan: ");
    scanf("%d", &pilihan);
    fflush(stdin);
    if (pilihan < 1 || pilihan >4)
    {
        printf("\nhmm.. kayaknya kamu salah ketik deh. Coba lagi yuk! \n");
        menu();
    }
    else if (head == NULL && (pilihan == 3 || pilihan == 4))
    {
        printf("Belom ada data nih.. insert awal atau akhir dulu yuk!\n");
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
            printf("\n%d gak ada di SLL, coba yang lain deh.\n", key);
            return;
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
                printf("\n%d gak ada di SLL, coba yang lain deh.\n", key);
                return;
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
    temp = head;
    printf("\nISI SLL\n");
    if (temp == NULL) printf("Belom ada data nih.. isi dulu yuk!\n");    
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void menu_delete()
{
    int pilihan;
    printf("\nMENU DELETE\n1. Delete awal\n2. Delete akhir\n3. Delete after\n4. Delete tertentu\n");
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

    default:
        printf("\nhmm.. kayaknya kamu salah ketik deh. Coba lagi yuk! \n");
        menu();
        break;
    }
    tampil();
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
            printf("\n%d gak ada di SLL, coba yang lain deh.\n", key);
            return;
        }
        after = after->next;    
    }
    hapus = after->next;
    if (hapus == NULL)
    {
        printf("tidak ada data yang dihapus");
        return;
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
            printf("\n%d gak ada di SLL, coba yang lain deh.\n", key);
            return;
        }
        ph = hapus;
        hapus = hapus->next;
    }
    if (head->data == key) del_awal();
    else ph->next = hapus->next;
    bebas();
}