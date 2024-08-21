#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TEXTSIZE 21

typedef struct item
{
    char *text;
    struct item *next;
} item_t;

typedef struct hash
{
    item_t **table;
    int size;
    int hash_key;
} hash_t;

// Write your code here
// ...

hash_t *init_hashtable(int m, int hk){
    hash_t *h=(hash_t*)malloc(sizeof(hash_t)) ; 
    h->hash_key = hk ;
    h->size = m ; 
    h->table = (item_t**)malloc(sizeof(item_t*)*m);
    for(int i=0;i<m;i++) h->table[i] = NULL ; 
    return h;
}
unsigned int fn(char *text , int hash_key,int n){
    if(n==0) return text[0]  ;
    return hash_key*fn(text,hash_key,n-1)  + text[n] ; 
}
unsigned int hash_index(char *text,int hash_key,int size){
    int n= strlen(text); 
    unsigned num = fn(text,hash_key,n-1);
    return num%size ; 
}



void insert(hash_t *hashtb, char *text){
    unsigned index = hash_index(text ,hashtb->hash_key,hashtb->size);
    item_t *new = (item_t*)malloc(sizeof(item_t));
    new->text = (char*)malloc(strlen(text)+1);
    strcpy(new->text,text);
    new->next = NULL ; 

    if(hashtb->table[index] == NULL) hashtb->table[index] = new ; 
    else{
        new->next = hashtb->table[index] ; 
        hashtb->table[index] = new ; 
    }



}
int search(hash_t *hashtb, char *text){
    unsigned int index = hash_index(text, hashtb->hash_key, hashtb->size);
    if (hashtb->table[index] == NULL) {
        return -1;
    } else {
        item_t *run = hashtb->table[index];
        while (run != NULL) {
            if (strcmp(run->text, text) == 0) {
                return index;
            }
            run = run->next;
        }
        return -1;
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