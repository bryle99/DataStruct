#include <stdio.h>
#include <string.h>

#define SIZE 50

typedef struct{
    char fname[16];
    char lname[16];
    char MI;
}nameType;

typedef struct{
    int id;
    nameType name;
    char course[8];
    int year;
}studType;

typedef struct{
    studType studs[SIZE];
    int count;
}LIST;

typedef struct{
    studType studes[SIZE];
    int last;
}LIST_V2;

void initList(LIST*);
void popList(LIST*);
void displayBSIT(LIST);
void insertPos(LIST*, studType, int);
void displayAll(LIST);
void deleteID(LIST*, int);
void insertSorted(LIST*, studType);
void selectionSort(LIST*);
void insertionSort(LIST*);


int main() {
    LIST A;
    studType insertThis = {6, {"Zacahry", "Parsacala", 'F'}, "BSIT", 2};
    
    initList(&A);
    popList(&A);
    displayBSIT (A);
    //insertPos(&A, insertThis, 4);
    insertSorted(&A, insertThis);
    selectionSort(&A);
    //insertionSort(&A);
    displayAll (A);
    deleteID(&A, 4);
    displayAll(A);
    selectionSort(&A);
    //insertionSort(&A);
    displayAll(A);
    return 0;
}

void initList(LIST *L){
    L->count = 0;
}

void popList(LIST *L) {
    int i;
    studType populate[5] = {
        {2, {"Bryle",       "Baran",   'A'}, "BSIT", 2},
        {3, {"Ranz",        "Sapa",    'B'}, "BSCS", 2},
        {1, {"JC",          "Del Mar", 'C'}, "BSIT", 2},
        {4, {"Daniel",      "Ubanan",  'D'}, "BSCS", 2},
        {5, {"Francis Von", "Arimbay", 'E'}, "BSIT", 2}
    };
    if (L->count < SIZE) {
        for (i = 0; i < 5; i++, L->count++) {
            L->studs[L->count] = populate[i];
            //insertSorted(L, populate[i]);
        }
    }
    
}

void displayBSIT(LIST L){
    int i;
    for(i=0; i<L.count; i++){
        if(!strcmp (L.studs[i].course, "BSIT")) {
            printf ("%s, %s %c\n", L.studs[i].name.lname, L.studs[i].name.fname, L.studs[i].name.MI);
        }
    }
}

void insertPos(LIST *L, studType x, int pos){
    if(pos>=0 && pos<SIZE && L->count<SIZE){
        memcpy (L->studs+pos+1, L->studs+pos, sizeof(studType) * (L->count - pos));
        L->studs[pos] = x;
        L->count++;
    }
    
}

void displayAll(LIST L){
    int i;
    printf("\n");
    for(i=0; i<L.count; i++){
        printf ("%s, %s %c\n", L.studs[i].name.lname, L.studs[i].name.fname, L.studs[i].name.MI);
    }
}

void deleteID(LIST *L, int ID){
    int i;
    if(L->count>0){
        for(i=0; i<SIZE && L->studs[i].id != ID; i++){}
        if(i<SIZE){
            memcpy(L->studs+i, L->studs+i+1, sizeof(studType) * (L->count - i));
            L->count--;
        }
    }
}

void insertSorted(LIST *L, studType x)
{
    int pos;
    if(L->count != SIZE){
        for(pos=0; pos < L->count && L->studs[pos].id < x.id; pos++){}
        memcpy(L->studs+pos+1, L->studs+pos, sizeof(studType) * (L->count - pos));
        L->studs[pos] = x;
        L->count++;
    }
}

void selectionSort(LIST *L)
{
    int x, y, swap;
    studType min, temp;
    for(x = 0; x < L->count-1; x++){
        min = L->studs[x];
        swap = x;
        for(y = x+1; y < L->count; y++){
            if(min.id > L->studs[y].id){
                min = L->studs[y];
                swap = y;
            }
        }
        temp = L->studs[x];
        L->studs[x] = min;
        L->studs[swap] = temp;
    }
}

void insertionSort(LIST *L)
{
    int x, y;
    studType sort;
    for(x = 0; x < L->count; x++){
        sort = L->studs[x];
        memcpy(L->studs+x, L->studs+x+1, sizeof(studType) * (L->count - x));
        for(y = 0; y < x+1 && sort.id < L->studs[y].id; y++){}
        memcpy(L->studs+y+1, L->studs+y, sizeof(studType) * (L->count - y));
        L->studs[y] = sort;
    }
}



