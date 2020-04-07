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
void tampil();
void del_akhir();
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
    printf("\nmau delete data akhir? (y/n) ");
    scanf("%c", &jwb);
    fflush(stdin);
    del_ini();
    printf("\nhapus data tertentu..\n");
    tampil();
    return 0;
}

void del_akhir()
{
    hapus = head;
    if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        while (hapus->next != NULL)
        {
            hapus = hapus->next;
        }
        hapus->prev->next = NULL;
    }
    bebas();
}

void bebas()
{
    free(hapus);
    hapus = NULL;
}

void bebas()
{
    free(hapus);
    hapus = NULL;
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