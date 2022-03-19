//In this file is my implementation of Lists in C language
//It's intended to create, and operate on Lists with a "Head" using C structs
//Operations consists of:
//Creating empty list
//Adding new element at the beginning of List
//Searching for word in a List
//Removing certain word from a List
//Printing out a list (either normally or backwards)
//Copying the list without repeating elements
//Merging of two lists

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Z głową
struct element
{
    char x[20];
    struct element * next, * prev;
};

struct element * utworzListe()
{
    struct element * Lista = malloc(sizeof(struct element));

    Lista->next = Lista;
    Lista->prev = Lista;
    return Lista;

}

struct element * dodajNaPocz(struct element * head, char a[])
{
    struct element * temp = malloc(sizeof(struct element));
    strcpy(temp->x, a);
    if(head->next == NULL){
        head->next = temp;
        head->prev = temp;
        temp->next = head;
        temp->prev = head;
        return temp;
    }
    temp->next = head->next;
    temp->next->prev = temp;
    head->next = temp;
    temp->prev = head;

    return temp;
}

/*struct element * dodajw(struct element * Lista, struct element * elem, int a)
{
    struct element * temp = malloc(sizeof(struct element));
    temp->x = a;
    temp->next = elem->next;
    elem->next = temp;
    return Lista;

}*/

struct element * szukaj(struct element * head, char s[])
{
    if(head->next == NULL) return NULL;
    struct element * temp = head->next;

    while(temp != head)
    {
        if(!strcmp(temp->x, s)) return temp;
        temp=temp->next;
    }
    return NULL;
};

void usun(struct element * head, char s[]){
    struct element * toremove = szukaj(head, s);
    while(toremove != NULL){
        toremove->next->prev = toremove->prev;
        toremove->prev->next = toremove->next;
        toremove = szukaj(head, s);
    }
}

void show(struct element * head)
{
    struct element * temp = head->next;
    if(temp==head)
    {
        printf("Lista jest pusta\n");
    }
    else{
            while(temp != head)
        {
            printf("%s\n", temp->x);
            temp = temp->next;
        }
    }
    printf("----\n");
}

void showBackwards(struct element * head)
{
    struct element * temp = head->prev;
    if(temp==head)
    {
        printf("Lista jest pusta\n");
    }
    else{
            while(temp != head)
        {
            printf("%s\n", temp->x);
            temp = temp->prev;
        }
    }
    printf("----\n");
}

void kasuj(struct element * head){
    if(head->next == head) free(head);

    else{
        head->prev->next = NULL;
        while(head->next != NULL){
            head = head->next;
            free(head->prev);
        }
        free(head);
    }
}

struct element * bezpowtorzen(struct element * head){
    struct element * kopia = utworzListe();
    struct element * kopia2 = utworzListe();
    struct element * temp = head->prev;
    while(temp != head){
        dodajNaPocz(kopia2, temp->x);
        temp = temp->prev;
    }
    show(kopia2);
    while(kopia2->next != kopia2)
    {
        dodajNaPocz(kopia, kopia2->prev->x);
        usun(kopia2, kopia2->prev->x);
    }
    return kopia;
};

struct element * scal(struct element * Lista1, struct element * Lista2){
    struct element * scalona = Lista1;
    struct element * temp = Lista1;
    while(temp->next != Lista1){
        temp = temp->next;
    }
    temp->next = Lista2->next;
    Lista2->next->prev = temp;
    while(temp->next != Lista2)
    {
        temp = temp->next;
    }
    temp->next = Lista1;
    temp->next->prev = temp;
    free(Lista1);
    return scalona;
};
int main()
{
    struct element * Head = utworzListe();

    //printf("Do przodu\n");
    //show(Head);
    //printf("Do tylu\n");
    //showBackwards(Head);

    struct element * pierwszy = dodajNaPocz(Head, "Adam");
    //printf("Do przodu\n");
    //show(Head);
    //printf("Do tylu\n");
    //showBackwards(Head);

    pierwszy = dodajNaPocz(Head, "Andrzej");
    //printf("Do przodu\n");
    //show(Head);
    //printf("Do tylu\n");
    //showBackwards(Head);

    pierwszy = dodajNaPocz(Head, "Roman");
  //  printf("Do przodu\n");
  //  show(Head);
   // printf("Do tylu\n");
   // showBackwards(Head);

    pierwszy = dodajNaPocz(Head, "Gietek");
   // printf("Do przodu\n");
   // show(Head);
   // printf("Do tylu\n");
  //  showBackwards(Head);

    pierwszy = dodajNaPocz(Head, "Andrzej");
  //  printf("Do przodu\n");
   // show(Head);
  //  printf("Do tylu\n");
   // showBackwards(Head);

    pierwszy = dodajNaPocz(Head, "Roman");
   // printf("Do przodu\n");
  //  show(Head);
  //  printf("Do tylu\n");
  //  showBackwards(Head);

    pierwszy = dodajNaPocz(Head, "Gietek");
    printf("Do przodu\n");
    show(Head);
    //printf("Do tylu\n");
    //showBackwards(Head);
    struct element * found = szukaj(Head, "Adam");
    if(found != NULL) printf("\nZnaleziono slowo %s w liscie\n----\n", found->x);
    struct element * found1 = szukaj(Head, "Gietek");
    if(found1 != NULL) printf("\nZnaleziono slowo %s w liscie\n----\n", found1->x);

    usun(Head, "Adam");
    show(Head);

    //dodajNaPocz(Head, "Adam");
    struct element * Headcopy = bezpowtorzen(Head);
    show(Head);
    show(Headcopy);

    struct element * scalona = scal(Head, Headcopy);
    show(scalona);
    //kasuj(scalona);





    return 0;
}
