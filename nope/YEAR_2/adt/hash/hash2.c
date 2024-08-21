#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 21

typedef char *item_t;
typedef struct hash
{
    item_t *table;
    int size;
    int hash_key;
} hash_t;
// Write your code here
// ...
hash_t *init_hashtable(int m , int hash_key){
    hash_t *p=(hash_t*)malloc(sizeof(hash_t));
    p->size =  m ; 
    p->hash_key = hash_key ; 
    p->table = (item_t*)malloc(sizeof(item_t)*m); 
    for(int i=0;i<m;i++) p->table[i] = NULL ; 
    return p ;
}
unsigned int fn(char *text , int hash_key,int n){
    if(n==0) return text[0]  ;
    return hash_key*fn(text,hash_key,n-1)  + text[n] ; 
}
unsigned int hash_index(char *text,int hash_key,int size){
    int n= strlen(text); 
    unsigned int num = fn(text,hash_key,n-1);
    return num%size ; 
}

void insert(hash_t *h , char *text){
    unsigned int index = hash_index(text,h->hash_key,h->size) ; 
    int i = 0  ; 
    while(1) {
        unsigned int nextid=(index + (i+i*i)/2)%h->size ;
        if(h->table[nextid] == NULL) {
            h->table[nextid] = (item_t)malloc(strlen(text)+1) ; 
            strcpy(h->table[nextid],text) ;
            break;
        }

        i++ ; 
    }
}   


int search(hash_t *h, char *text) {
    unsigned int index = hash_index(text, h->hash_key, h->size);
    if (h->table[index] != NULL && strcmp(h->table[index], text) == 0) {
        return index; 
    } 
    else {
        int i = 0;
        while (1) {
            unsigned int nextid = (index + (i + i * i) / 2) % h->size;
            if (h->table[nextid] != NULL && strcmp(h->table[nextid], text) == 0) {
                return nextid;
            }
            if (h->table[nextid] == NULL) {
                return -1; 
            }
            i++;
        }
    }
}


int main(void)
{
    hash_t *hashtable = NULL;
    char *text = NULL;
    int m, n, i, hash_key;
    int command;
    scanf("%d %d %d", &m, &n, &hash_key);
    hashtable = init_hashtable(m, hash_key);
    text = (char *)malloc(sizeof(char) * TEXTSIZE);
    for (i = 0; i < n; i++)
    {
        scanf("%d %s", &command, text);
        switch (command)
        {
        case 1:
            insert(hashtable, text);
            break;
        case 2:
            printf("%d\n",
                   search(hashtable, text));
            break;
        }
    }
    return 0;
}