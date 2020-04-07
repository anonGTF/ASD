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
void awal();
void akhir();
void after();
void before();
void del_awal();
void del_akhir();
void del_ini();
void bebas();
void tampil();
void menu_ins();
void menu_del();
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
        menu_ins();
    }
    else if (pilihan == 2)
    {
        menu_del();
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

void menu_del()
{
    int pilihan;
    printf("\nMENU DELETE\n1. Delete awal\n2. Delete akhir\n3. Delete tertentu\n");
    printf("masukan pilihan delete: ");
    scanf("%d", &pilihan);
    switch (pilihan)
    {
    case 1:
        printf("\nMenghapus data awal...\n");
        del_awal();
        break;
    
    case 2:
        printf("\nMenghapus data akhir...\n");
        del_akhir();
        break;

    case 3:
        del_ini();
        printf("\nMenghapus data yang dipilih...\n");
        break;

    default:
        printf("\nhmm.. kayaknya kamu salah ketik deh. Coba lagi yuk! \n");
        return;
        break;
    }
    tampil();
}

void menu_ins()
{
    int pilihan;
    printf("\n\nMENU INSERT DLL:\n1. Awal\n2. Akhir\n3. After\n4. Before\n");
    printf("masukan pilihan: ");
    scanf("%d", &pilihan);
    fflush(stdin);
    if (head == NULL && (pilihan == 3 || pilihan == 4))
    {
        printf("belum ada data.. insert awal atau akhir dulu\n");
        return;
    }
    else if (pilihan < 1 || pilihan > 5)
    {
        printf("pilihan tidak valid\n");
        return;
    }
    else
    {
        alokasi();
        switch (pilihan)
        {
        case 1:
            awal();
            break;
        case 2:
            akhir();
            break;
        case 3:
            after();
            break;
        case 4:
            before();
            break;
        }
    }
    tampil();
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

void before()
{
    Dnode *bef = head;
    int key;
    printf("masukan sebelum: ");
    scanf("%d", &key);
    fflush(stdin);
    if (head->no == key)
    {
        awal();
    }
    else
    {
        while (bef->no != key)
        {
            if (bef->next == NULL)
            {
                printf("%d tidak ada di DLL", key);
                exit(0);
            }
            bef = bef->next;
        }
        temp->next = bef;
        temp->prev = bef->prev;
        bef->prev->next = temp;
        bef->prev = temp;
    }
    
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

void awal()
{
    if (head != NULL)
    {
        temp->next = head;
        head->prev = temp;
    }
    head = temp;
}

void del_ini()
{
    int key;
    hapus = head;
    printf("hapus yang: ");
    scanf("%d", &key);
    fflush(stdin);
    if (head->no == key)
    {
        del_awal();
    }
    else
    {
        while (hapus->no != key)
        {
            if (hapus->next == NULL)
            {
                printf("%d tidak ada di DLL", &key);
                exit(0);
            }
            hapus = hapus->next;
        }
        hapus->prev->next = hapus->next;
        if (hapus->next != NULL)
        {
            hapus->next->prev = hapus->prev;
        }
        hapus->next = NULL;
        hapus->prev = NULL;
        bebas();
    }
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

void del_awal()
{
    hapus = head;
    if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }
    bebas();
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
            printf("%d\t%s\t%d\n", temp->no, temp->nama, temp->nilai);
            temp = temp->next;
        }
        return;
    }
}