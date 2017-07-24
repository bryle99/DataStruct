#include <stdio.h>
#include <stdlib.h>

#define max 6

typedef struct{
    char elem;
    int next;
}cell;

typedef cell HeapSpace[max];

typedef struct{
    HeapSpace H;
    int avail;
}VirtualHeap;

typedef struct{
    int indextoElem;
    VirtualHeap *VHPtr;
}LIST;

typedef enum{
    TRUE, FALSE
}boolean;

void initializeVH_v1(VirtualHeap *);
void initializeVH_v2(VirtualHeap *);
int doMalloc(VirtualHeap *);
void doFree(VirtualHeap *, int);
void initializeLIST(LIST *, VirtualHeap *);
boolean isMember(LIST, char x);
void delFirstOccur(LIST *, char);
void insertSorted(LIST*, char);
void popList(LIST*);
void displayList(LIST);

int main() {
    VirtualHeap VH;
    LIST L;
    
    initializeVH_v2(&VH);
    initializeLIST(&L, &VH);
    popList(&L);
    displayList(L);
    
    if(isMember(L, 'a') == TRUE){
        printf("\nTRUE\n");
    }else{
        printf("\nFALSE\n");
    }
    
    
    delFirstOccur(&L, 'a');
    displayList(L);
    
    if(isMember(L, 'a') == TRUE){
        printf("\nTRUE\n");
    }else{
        printf("\nFALSE\n");
    }
    
    insertSorted(&L, 'd');
    displayList(L);
    
    return 0;
}

void initializeVH_v1(VirtualHeap *VH)
{
    int i ;
    VH->avail = 0;
    for(i= max-2; i <= 0; i--){
        VH->H[i].next = i+1;
    }
    VH->H[max-1].next = -1;
}

void initializeVH_v2(VirtualHeap *VH)
{
    int i;
    VH->avail = max-1;
    for(i = max-1; i >= 0; i--){
        VH->H[i].next = i-1;
    }
}

int doMalloc(VirtualHeap *VH)
{
    int ret;
    ret = VH->avail;
    if(ret >= 0){
        VH->avail = VH->H[ret].next;
    }
    return ret;
}

void doFree(VirtualHeap *VH, int x)
{
    VH->H[x].next = VH->avail;
    VH->avail = x;
}

void initializeLIST(LIST *L, VirtualHeap *VH)
{
    L->indextoElem = -1;
    L->VHPtr = VH;
}

boolean isMember(LIST L, char x)
{
    int trav;
    for(trav = L.indextoElem; trav != -1 && L.VHPtr->H[trav].elem != x; trav = L.VHPtr->H[trav].next){}
    return (trav != -1)? TRUE: FALSE;
}

void delFirstOccur(LIST *L, char x)
{
    int *trav, temp;
    for(trav = &L->indextoElem; *trav != -1 && L->VHPtr->H[*trav].elem != x; trav = &L->VHPtr->H[*trav].next){}
    if(*trav != -1){
        temp = *trav;
        *trav = L->VHPtr->H[temp].next;
        doFree(L->VHPtr, temp);
    }
}

void insertSorted(LIST *L, char x)
{
    int *trav, temp;
    for(trav = &L->indextoElem; *trav != -1 && L->VHPtr->H[*trav].elem < x; trav = &L->VHPtr->H[*trav].next){}
    temp = doMalloc(L->VHPtr);
    if(temp != -1){
        L->VHPtr->H[temp].elem = x;
        L->VHPtr->H[temp].next = *trav;
        *trav = temp;
    }
}

void popList(LIST *L)
{
    int ctr;
    char insertThese[4] = {'b', 'a', 'e', 'c'};
    for(ctr = 0; ctr < 4; ctr++){
        insertSorted(L, insertThese[ctr]);
    }
}

void displayList(LIST L)
{
    for(; L.indextoElem != -1; L.indextoElem = L.VHPtr->H[L.indextoElem].next){
        printf("%c\n", L.VHPtr->H[L.indextoElem].elem);
    }
}


