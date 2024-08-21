#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodee {
    int *sortArray;
    char name[50];
    struct nodee *next;
} node;

void make_sort(int arr[], int n) {
    int i;
    int p1 = 0, p2 = 1;
    while (p2 != n) {
        if (arr[p1] < arr[p2]) {
            p1++;
            p2++;
        } else {
            // check
            int k1 = p1, k2 = p2;
            while (arr[k1] > arr[k2] && k1 != -1) {
                int swp = arr[k2];
                arr[k2] = arr[k1];
                arr[k1] = swp;
                k1--;
                k2--;
            }
            p1++;
            p2++;
        }
    }
}

node *init_node(node *s) {
    int i;
    node*run=s;
    node *p = (node *)malloc(sizeof(node));
    scanf("%s", p->name);
    int str_len = strlen(p->name);
    // printf("%s\n", p->name);
    // printf("strlen : %d\n", strlen(p->name));
    // int array
    p->sortArray = (int *)malloc(sizeof(int) * str_len);
    for (i = 0; i < str_len; i++) p->sortArray[i] = p->name[i];
    // for (i = 0; i < str_len; i++) printf("%d ", p->sortArray[i]);
    // AFTER sort
    make_sort(p->sortArray, str_len);
    // for (i = 0; i < str_len; i++) printf("%d ", p->sortArray[i]);
    p->next = NULL;

    if (s == NULL)
        return p;
    while(run->next != NULL){
        run=run->next;
    }
    run->next = p;
    return s;
}


int check_arr(int arr1[], int arr2[], int c,int r) {
    if(c != r) return 0;
    for (int i = 0; i < c; i++) {
        if (arr1[i] != arr2[i]) return 0;
    }
    return 1;
}

int main() {
    int m, n, i;
    node *s = NULL;
    scanf("%d %d", &m, &n);
    for (i = 0; i < m; i++) {
        s = init_node(s);
    }
    for(i=0;i<n;i++){
        node *run = s;
        node *c =NULL;
        c=init_node(c);
        while(run!=NULL){
            printf("%d\n",strlen(c->name));
            printf("%d",strlen(run->name));
            if(check_arr(c->sortArray,run->sortArray,strlen(c->name),strlen(run->name)) == 1){
                printf("%s ",run->name);
            }
            run=run->next;
        }
        printf("\n");
    }

    return 0;
}