#include <stdio.h>
#include <stdlib.h>

#define SIZE 30

typedef enum{
    TRUE, FALSE
}boolean;

typedef struct {
    char elem[SIZE];
    int last;
}List_v1;

typedef struct{
    char elem[SIZE];
    int last;
}*List_v2, lType_v2;

typedef struct{
    char elem[SIZE];
}elem;

typedef struct {
    elem *elemptr;
    int last;
}List_v3;

typedef struct{
    elem *elemptr;
    int last;
}*List_v4, lType_v4;

void initializeList_v1(List_v1*);
void initializeList_v2(List_v2*);
void initializeList_v3(List_v3*);
void initializeList_v4(List_v4*);
boolean isMember_v1(List_v1, char);
boolean isMember_v2(List_v2, char);
boolean isMember_v3(List_v3, char);
boolean isMember_v4(List_v4, char);

int main() {
    List_v1 A;
    List_v2 B;
    List_v3 C;
    List_v4 D;
    
    initializeList_v1(&A);
    initializeList_v2(&B);
    initializeList_v3(&C);
    initializeList_v4(&D);
    
    int version;
    char input;
    boolean result;
    
    printf ("Enter character element:");
    scanf ("%c", &input);
    printf("\n Enter array-list version(1, 2 ,3 ,4):");
    scanf ("%d", &version);
    switch(version){
        case 1:
            break;
            
    }
    return 0;
}

void initializeList_v1(List_v1 *L)
{
    L->last = -1;
}

void initializeList_v2(List_v2 *L)
{
    (*L) = (List_v2) malloc(sizeof (lType_v2));
    (*L)->last = -1;
}

void initializeList_v3(List_v3 *L)
{
    L->elemptr = (elem*) malloc(sizeof(elem));
    L->last = -1;
}

void initializeList_v4(List_v4 *L)
{
    *L = (List_v4) malloc(sizeof(lType_v4));
    (*L)->elemptr =  (elem*) malloc(sizeof(elem));
    (*L)->last = -1;
}


boolean isMember_v1(List_v1 L, char x)
{
    int i;
    for(i=0; i <= L.last && L.elem[i] != x; i++){}
    return (i <= L.last)? TRUE: FALSE;
}

boolean isMember_v2(List_v2 L, char x)
{
    int i;
    for(i=0; i <= L->last && L->elem[i] != x; i++){}
    return (i <= L->last)? TRUE: FALSE;
}

boolean isMember_v3(List_v3 L, char x)
{
    int i;
    for(i=0; i <= L.last && L.elemptr->elem[i] != x; i++){}
    return (i <= L.last)? TRUE: FALSE;
}

boolean isMember_v4(List_v4 L, char x)
{
    int i;
    for(i=0; i <= L->last && L->elemptr->elem[i] != x; i++){}
    return (i <= L->last)?TRUE: FALSE;s
