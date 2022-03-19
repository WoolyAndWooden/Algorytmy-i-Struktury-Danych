#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WORDS_LENGTH 3744
#define HASH_PRIMARY 2053
#define HASH_NOTPRIMARY 2048

int hash(char *word){
    int len = 30;
    int S = 7;
    int result = S*word[0] + word[1];
    if(word[1] == 0) return result;
    for(int i = 2; i < len; i++)
    {
        if(word[i] == 0) return result;
        result *= S+word[i];
    }
    return result;
}

int max(int tab[], int len){
    int max = tab[0];
    for(int i = 1; i < len; i++)    if(tab[i] > max)    max = tab[i];
    return max;
}
double mean(int tab[], int len){
    double mean = 0;
    int counter = 0;
    for(int i = 0; i < len; i++){
        if(tab[i] != 0){
            counter++;
            mean += tab[i];
        }
    }
    return mean/counter;
}
int main(){
    //setup
    clock_t start, end;
    char words[WORDS_LENGTH][30];
    FILE *fr;
    fr = fopen("words.txt","r");

    if(fr == NULL){
        printf("Error!");
        return(1);
    }

    for(int i = 0; i < 3744; i++){
        char word[30];
        fscanf(fr, "%s\n", &word);
        strcpy(words[i], word);
    }
    fclose(fr);
    int Tprim[HASH_PRIMARY] = {0};
    int Tsquare[HASH_NOTPRIMARY] = {0};

    //Primary number sized table time check
    start = clock();

    for(int i = 0; i < WORDS_LENGTH - 1; i++){
        Tprim[hash(words[i])%HASH_PRIMARY]++;
    }

    end = clock();

    double time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%lf\n", time_used);

    //Power of 2 sized table time check
    start = clock();

    for(int i = 0; i < WORDS_LENGTH; i++){
        Tsquare[hash(words[i])%HASH_NOTPRIMARY]++;
    }

    end = clock();

    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%lf\n", time_used);

    int zeroes = 0;
    for(int i = 0; i < HASH_PRIMARY; i++)   if(Tprim[i] == 0) zeroes++;
    printf("Table of primary number size:\nAmount of non colision spaces: %d\nMax collisions on key: %d\nMean of collision spaces: %f\n",
           zeroes, max(Tprim, HASH_PRIMARY), mean(Tprim, HASH_PRIMARY));

    zeroes = 0;
    for(int i = 0; i < HASH_NOTPRIMARY; i++)   if(Tsquare[i] == 0) zeroes++;
    printf("Table of power of 2 number size:\nAmount of non colision spaces: %d\nMax collisions on key: %d\nMean of collision spaces: %f\n",
           zeroes, max(Tsquare, HASH_NOTPRIMARY), mean(Tsquare, HASH_NOTPRIMARY));


    return 0;
}
