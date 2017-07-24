#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum{
    TRUE, FALSE
}boolean;

typedef struct{
    char fname[24];
    char lname[24];
    char mi;
}nameType;

typedef struct node{
    nameType elem;
    struct node *link;
}*List;

void initializeList(List*);
void insertSorted(List*, nameType);
void insertLast(List*, nameType);
void insertionSort(List*); /* Ascending order*/
void populateList(List*);
void displayList(List);
boolean isSorted(List);
nameType delLastName(List*, char[]);
void delAllOccurrence(List*, char[]);
void delDuplicate(List);


int main() {
    int i;
    List L;
    nameType deleted;
    
    
    initializeList (&L);
    populateList (&L);
    displayList (L);
    
    if(isSorted (L) == TRUE){
        printf ("\nList is sorted");
    }else{
        printf("\nList is not sorted");
    }
    
    deleted = delLastName (&L, "Baran");
    displayList (L);
    printf("\n Deleted record: %s, %s %c", deleted.lname, deleted.fname, deleted.mi);
    
    
    
    return 0;
}

void initializeList(List *L)
{
    *L = NULL;
}

void insertSorted(List *L, nameType x)
{
    List *trav, temp;
    for(trav = L; *trav != NULL && strcmp ((*trav)->elem.lname, x.lname) <= 0; trav = &(*trav)->link){}
    temp = (List) malloc(sizeof(struct node));
    if(temp != NULL) {
        temp->elem = x;
        temp->link = *trav;
        *trav = temp;
    }
}

void insertLast(List *L, nameType x)
{
    List *trav, temp;
    for(trav = L; *trav != NULL; trav = &(*trav)->link){}
    temp = (List) malloc(sizeof(struct node));
    if(temp != NULL){
        temp->elem = x;
        temp->link = *trav;
        *trav = temp;
    }
}

void insertionSort(List *L)
{
    List *trav, *sortThis, *next, temp;
    for(sortThis = &(*L)->link; sortThis != NULL; sortThis = next){
        next = &(*sortThis)->link;
        for(trav = L; *trav != NULL && strcmp((*trav)->elem.lname, (*sortThis)->elem.lname) <= 0; trav = &(*trav)->link){}
        (*sortThis)->link = *trav;
        *trav = *sortThis;
    }
}

void populateList(List *L)
{
    List *trav, temp;
    int i;
    nameType studs[4] = {{"Bryle", "Baran", 'A'}, {"Sofia", "Garcia", 'G'}, {"Ranz", "Sapa", 'K'}, {"Francis", "Arimbay", 'A'}};
    
    for(i=0; i<4; i++){
        insertSorted (L, studs[i]);
    }
    
    
}

void displayList(List L)
{
    for(; L != NULL; L = L->link){
        printf("\n%s, %s %c ", L->elem.lname, L->elem.fname, L->elem.mi);
    }
}

boolean isSorted(List L)
{
    for(; L->link != NULL && strcmp(L->elem.lname, L->link->elem.lname) <= 0; L = L->link){}
    return (L->link != NULL)?FALSE : TRUE;
}

nameType delLastName(List *L, char x[])
{
    List *trav, temp;
    for(trav = L; *trav != NULL && strcmp ((*trav)->elem.lname, x) != 0; trav = &(*trav)->link){}
    if(*trav != NULL){
        temp =  *trav;
        *trav = (*trav)->link;
        free(temp);
    }
    return temp->elem;
}

void delAllOccurrence(List *L, char x[])
{
    List *trav, temp;
    for(trav = L; *trav != NULL;){
        if(strcmp((*trav)->elem.lname, x) == 0){
            temp = *trav;
            *trav = (*trav)->link;
            free(temp);
        }else{
            trav = &(*trav)->link;
        }
    }
}

void delDuplicate(List L)
{
    List x, *y, temp;
    for(x = L; x != NULL; x = x->link){
        for(y = &x->link; *y != NULL;){
            if(strcmp(x->elem.lname, (*y)->elem.lname) == 0){
                temp = *y;
                *y = temp->link;
                free(temp);
            }else{
                y = &(*y)->link;
            }
        }
    }
}
