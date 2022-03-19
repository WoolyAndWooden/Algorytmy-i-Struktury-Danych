#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<stdbool.h>

#define NAZWISKA 20000

struct element{
    //-1 = DEL
    int ilosc;
    char nazwisko[30];
};

unsigned long int wordToInt(char *word){
    int len = 30;
    int S = 7;
    unsigned long int result = S*word[0] + word[1];
    if(word[1] == 0) return result;
    for(int i = 2; i < len; i++)
    {
        if(word[i] == 0)
        {
            return result;
        }
        result *= S+word[i];
    }
    return result;
}
void fillWithEmpty(struct element tab[], int size){
    for(int i = 0; i < size; i++){
        tab[i].ilosc = -2;
    }
}
int hashLinear(unsigned long int k, int m, int i){
    return (h1(k, m) + i)%m;
}

int h1(unsigned long int k, int m){
    return k%m;
}

bool insert(struct element hashTable[], struct element toInsert, int size){
    unsigned long int k = wordToInt(toInsert.nazwisko);
    for(int i = 0; i < size; i++){
        int n = hashLinear(k, size, i);
        if(hashTable[n].ilosc < 0){
            hashTable[n] = toInsert;
            return true;
        }
    }
    return false;
}

bool DEL(struct element hashTable[], struct element toInsert, int size){
    unsigned long int k = wordToInt(toInsert.nazwisko);
    for(int i = 0; i < size; i++){
        int n = hashLinear(k, size, i);
        if(hashTable[n].ilosc == toInsert.ilosc && strcmp(hashTable[n].nazwisko, toInsert.nazwisko) == 0){
            hashTable[n].ilosc = -1;
            strcpy(hashTable[n].nazwisko, "");
            return true;
        }
    }
    return false;
}

int main(){
    //setup
    struct element words[20000];
    FILE *fr;
    fr = fopen("nazwiskaASCII.txt","r");
    if(fr == NULL){
        printf("Error!");
        return(1);
    }


    for(int i = 0; i < 20000; i++){
        char word[30];
        fscanf(fr, "%s\n", &word);
        words[i].ilosc = atoi(word);
        fscanf(fr, "%s\n", &word);
        strcpy(words[i].nazwisko, word);
    }
    fclose(fr);

    struct element TestTable[20];
    fillWithEmpty(TestTable, 20);
    for(int i = 0; i < 20; i++){
        insert(TestTable, words[i], 20);
    }
    //DEL(TestTable, words[10], 20);
    for(int i = 0; i < 20; i++) printf("%d: %s\n", i, TestTable[i].nazwisko);

    struct element TestTableBig[20000];
    fillWithEmpty(TestTableBig, 20000);


    for(int i = 0; i < 16000; i++){
        insert(TestTableBig, words[i], 20000);
    }
    int counter = 0;
    for(int i = 0; i < 16000; i+=2)
    {
        DEL(TestTableBig, words[i], 20000);
    }
    counter = 0;
    for(int i = 19999; i > 4000; i-=2){
        insert(TestTableBig, words[i], 20000);
    }
    for(int i = 0; i < 20000; i++) if(TestTableBig[i].ilosc == -1) counter++;
    printf("%d", counter);


    return 0;
}
