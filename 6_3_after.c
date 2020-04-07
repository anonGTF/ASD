#include<stdio.h>
#include<stdlib.h>

typedef struct dnode{
    struct dnode *prev;
    int no;
    char nama[255];
    int nilai;
    struct dnode *next;
} Dnode;

Dnode *head;
Dnode *temp;
Dnode *hapus;

void alokasi();
void akhir();
void after();
void tampil();
void bebas();

int main(){
    char jwb;
    do
    {
        alokasi();
        akhir();
        printf("masukan lagi? (y/n) ");
        scanf("%c", &jwb);
        fflush(stdin);
    } while (jwb == 'Y' || jwb == 'y');
    tampil();
    printf("\nmasukan data lagi? (y/n) ");
    scanf("%c", &jwb);
    fflush(stdin);
    alokasi();
    after();
    tampil();
    return 0;
}

void alokasi()
{
    temp = (Dnode*)malloc(sizeof(Dnode));
    if (temp == NULL)
    {
        printf("malloc gagal");
        exit(0);
    }
    printf("\nNo\t:");
    scanf("%d", &temp->no);
    fflush(stdin);
    printf("Nama\t:");
    gets(temp->nama);
    fflush(stdin);
    printf("Nilai\t:");
    scanf("%d", &temp->nilai);
    fflush(stdin);
    temp->next = NULL;
    temp->prev = NULL;
}

void after()
{
    Dnode *after = head;
    int key;
    printf("\nmasukan data setelah: ");
    scanf("%d", &key);
    fflush(stdin);
    while (after->no != key)
    {
        if (!after->next)
        {
            printf("%d tdk ada di DLL", key);
            exit(0);
        }
        after = after->next;
    }
    //printf("after data: %d", after->data);
    temp->prev = after;
    temp->next = after->next;
    if (after->next)
    {
        after->next->prev = temp;
    }
    after->next = temp;
}

void akhir()
{
    Dnode *tail = head;
    if (!head)
    {
        head = temp;
    }
    else
    {
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        temp->prev = tail;
        tail->next = temp;
    }
}


void tampil()
{
    temp = head;

    if (head == NULL)
    {
        printf("\ntidak ada data dalam SLL\n");
        return;
    }
    else
    {
        printf("\ndata yang telah diinputkan:\n");
        printf("No\tNama\tNilai\n");
        while (temp != NULL)
        {
            printf("%d\t%s\t%d\n", temp->no, temp->nama, temp->nilai);
            temp = temp->next;
        }
        return;
    }
}