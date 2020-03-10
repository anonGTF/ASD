#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head;
Node *hapus;
Node *temp;

void ins();
void del();
void src();
void menu();
void tampil();
void alokasi();
void bebas();

int main(){
    while (1)
    {
        menu();
    }
    return 0;
}

void menu()
{
    int pilihan;
    printf("\n\nMENU:\n1. Insert\n2. Delete\n3. Cari\n4. Exit\n");
    printf("Masukan pilihan kamu: ");
    scanf("%d", &pilihan);
    fflush(stdin);
    if (head == NULL && pilihan == 2)
    {
        printf("\nBelum ada data nih.. insert dulu yuk!\n");
        return;
    }
    else if (pilihan < 1 || pilihan > 4)
    {
        printf("\nHmm.. kayanya kamu salah pencet. Coba lagi yah.\n");
        return;
    }
    else
    {
        switch (pilihan)
        {
        case 1:
            ins();
            break;
        case 2:
            del();
            break;
        case 3:
            src();
            break;
        case 4:
            exit(0);
        default:
            printf("\nHmm.. kayanya kamu salah pencet. Coba lagi yah.\n");
            return;
        }
    }
}

void ins()
{
    Node *bef_key, *key = head;
    
    //alokasi
    alokasi();
    
    //cari dan sambungkan
    if (head == NULL || temp->data <= head->data)
    {
        if (head != NULL)
        {
            temp->next = head;
        }
        head = temp;
    }
    else
    {
        while (key->data < temp->data)
        {
            bef_key = key;
            if (key->next != NULL)
            {
                key = key->next;
            }
            else break;
        }
        temp->next = bef_key->next;
        bef_key->next = temp;
    }

    tampil();
}

void del()
{
    int key;
    hapus = head;
    Node *bef;
    //cari
    printf("mana yang pgn dihapus: ");
    scanf("%d", &key);
    fflush(stdin);
    while (hapus->data != key)
    {
        if (hapus->next == NULL)
        {
            printf("\n%d gak ada di SLL.. Coba lagi yah.\n", key);
            return;
        }
        bef = hapus;
        hapus = hapus->next;
    }

    //selamatkan
    if (head->data == key)
    {
        if (hapus->next == NULL) head = NULL;
        else head = hapus->next;
    }
    else bef->next = hapus->next;

    //bebaskan
    bebas();

    tampil();
}

void src()
{
    int key, exist = 0;
    Node *src = head;
    printf("angka berapa yg dicari: ");
    scanf("%d", &key);
    fflush(stdin);
    while (src != NULL)
    {
        if (src->data == key)
        {
            exist++;
            break;
        }
        else if (src->data > key)
        {
            break;
        }
        src = src->next;
    }
    if (exist > 0)
    {
        printf("\n%d ada di SLL\n", key);
    }
    else
    {
        printf("\n%d gak ada di SLL\n", key);
    }
}

void tampil()
{
    Node *temp = head;
    printf("\nISI SLL\n");
    if (head == NULL)
    {
        printf("gak ada data di SLL..");
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
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
    temp->next = NULL;
}

void bebas()
{
    free(hapus);
    hapus = NULL;
}
