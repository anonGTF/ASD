#include<stdio.h>
#include<stdlib.h>

typedef struct dnode{
    struct dnode *prev;
    int no;
    char nama[255];
    float nilai;
    struct dnode *next;
} Dnode;

Dnode *head;
Dnode *temp;
Dnode *hapus;

void insertsion();
void delete();
void search();
void avg();
void alokasi();
void bebas();
void tampil();
void menu();


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
    printf("\n\nMENU DLL:\n1. Insert\n2. Search\n3. Avg score\n4. Delete\n5. Exit\n");
    printf("masukan pilihan: ");
    scanf("%d", &pilihan);
    fflush(stdin);
    if (head == NULL && pilihan == 3)
    {
        printf("belum ada data.. insert dulu yuk\n");
        return;
    }
    else if (pilihan < 1 || pilihan > 5)
    {
        printf("pilihan tidak valid\n");
        return;
    }
    else if (pilihan == 5)
    {
        exit(0);
    }
    else
    {
        switch (pilihan)
        {
        case 1:
            insertsion();
            break;
        case 2:
            search();
            break;
        case 3:
            avg();
            break;
        case 4:
            delete();
            break;
        }
    }
}

void insertsion()
{
    Dnode *key = head;
    
    //alokasi
    alokasi();
    
    //cari dan sambungkan
    if (head == NULL || temp->no <= head->no)
    {
        if (head)
        {
            temp->next = head;
            head->prev = temp;
        }
        head = temp;
    }
    else
    {
        while (key->no < temp->no)
        {
            if (key->next) key = key->next;
            else break;
        }
        if (key->no < temp->no)
        {
            temp->prev = key;
            key->next = temp;
        }
        else
        {
            temp->prev = key->prev;
            temp->next = key;
            key->prev->next = temp;
            key->prev = temp;
        }
    }

    tampil();
}

void delete()
{
    int key;
    hapus = head;
    //cari
    printf("mana yang pgn dihapus: ");
    scanf("%d", &key);
    fflush(stdin);
    while (hapus->no != key)
    {
        if (!hapus->next)
        {
            printf("\n%d gak ada di SLL.. Coba lagi yah.\n", key);
            return;
        }
        hapus = hapus->next;
    }

    //selamatkan
    if (head->no == key)
    {
        if (!hapus->next) head = NULL;
        else head = hapus->next;
    }
    else hapus->prev->next = hapus->next;

    //bebaskan
    bebas();

    tampil();
}

void search()
{
    int key, exist = 0;
    Dnode *src = head;
    printf("angka berapa yg dicari: ");
    scanf("%d", &key);
    fflush(stdin);
    while (src)
    {
        if (src->no == key) exist++;
        else if (src->no > key) break;
        src = src->next;
    }
    if (exist > 0) printf("\n%d ada %d di DLL\n", key, exist); 
    else printf("\n%d gak ada di SLL\n", key);
    
}

void avg()
{
    float total = 0, my_avg;
    int count = 0;
    temp = head;
    if (head == NULL)
    {
        printf("\ntidak ada data dalam SLL\n");
        return;
    }
    else
    {
        while (temp != NULL)
        {
            total += temp->nilai;
            count++;
            temp = temp->next;
        }
        my_avg = total/count;
        printf("\nNilai rata-rata: %.2f\n", my_avg);
        return;
    }
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
    scanf("%f", &temp->nilai);
    fflush(stdin);
    temp->next = NULL;
    temp->prev = NULL;
}

void bebas()
{
    free(hapus);
    hapus = NULL;
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
            printf("%d\t%s\t%.0f\n", temp->no, temp->nama, temp->nilai);
            temp = temp->next;
        }
        return;
    }
}