#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node_t;
typedef node_t bst_t;

bst_t *insert(bst_t *t, int data)
{
    bst_t *p = (bst_t *)malloc(sizeof(bst_t));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    ///
    if (t == NULL) return p;
    if (data > t->data){
        if (t->right == NULL) t->right = p;
        else insert(t->right, data);
    }
    else{
        if (t->left == NULL) t->left = p;
        else insert(t->left, data);
    }

    return t;
}



int find(bst_t *t, int data)
{
    if (t == NULL)
        return 0;
    if (t->data == data)
        return 1;
    if (data < t->data)
        return find(t->left, data);
    else if (data > t->data)
        return find(t->right, data);
}
int find_min(bst_t *t)
{
    bst_t *run = t;
    while (run->left != NULL)
        run = run->left;
    return run->data;
}

int find_max(bst_t *t)
{
    bst_t *run = t;
    while (run->right != NULL)
        run = run->right;
    return run->data;
}

bst_t *delete(bst_t *t, int data){
    bst_t *runDELETE =NULL;
    if (t == NULL)
        return t;
    if (t->data == data){
        ////case 1 
        if(t->left == NULL && t->right == NULL){
            free(t);
            return NULL ; 
        }

        ////case 3
        else if(t->left != NULL && t->right != NULL){

            int dataRep = find_min(t->right);
            t->data = dataRep ; 
            t->right = delete(t->right,dataRep);
            return t ;
        }

        ////case 2
        else if (t->right != NULL){
            runDELETE = t->right;
            free(t);
            return runDELETE ; 
        }
        else if (t->left != NULL){
            runDELETE = t->left;
            free(t);
            return runDELETE ;  
        }
        


    }
    if (data < t->data) 
        t->left =  delete(t->left, data);
    else 
        t->right = delete(t->right, data);
    
    return t; 
}
int main(void)
{
    bst_t *t = NULL,*k=NULL;
    int n, i;
    int command, data;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &command);
        switch (command)
        {
        case 1:
            scanf("%d", &data);
            t = insert(t, data);
            break;
        case 2: 
            scanf("%d", &data); 
            t = delete(t, data); 
            break; 
        case 3:
            scanf("%d", &data);
            printf("%d\n", find(t, data));
            break;
        case 4:
            printf("%d\n", find_min(t));
            break;
        case 5:
            printf("%d\n", find_max(t));
            break;
        }
    }
    return 0;
}
