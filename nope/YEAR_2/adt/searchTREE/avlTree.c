#include <stdio.h>
#include <stdlib.h>
#include <week9.h>
#ifndef __avl_tree__
typedef struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;
} node_t;
typedef node_t avl_t;
#endif

// Write your code here
// ** Note that the print_tree() function // has been implemented already and // included in the week9.h header // ...

int find_min(avl_t *t)
{
    avl_t *run = t;
    while (run->left != NULL)
        run = run->left;
    return run->data;
}

int height(avl_t *t)
{
    if (t == NULL)
        return -1;
    return t->height;
}

int is_balance(avl_t *t)
{
    int HL = height(t->left);
    int HR = height(t->right);
    if (abs(HL - HR) != 1)
        return 0;
    else
        return 1;
}

int update_h(avl_t *t)
{
    int HL = -1;
    int HR = -1;
    if (t == NULL)
    {
        return -1;
    }
    if (t->left != NULL)
    {
        HL = t->left->height;
    }
    if (t->right != NULL)
    {
        HR = t->right->height;
    }
    if (HL > HR)
    {
        return HL + 1;
    }
    return HR + 1;
}



avl_t *right_rotation(avl_t *t)
{
    avl_t *head = t;
    avl_t *new = t->left;
    head->left = new->right;
    new->right = head;
    head->height = update_h(head);
    new->height = update_h(new);

    return new;
}

avl_t *left_rotation(avl_t *t)
{
    avl_t *head = t;
    avl_t *new = t->right;
    head->right = new->left;
    new->left = head;
    head->height = update_h(head);
    new->height = update_h(new);
    return new;
}

avl_t *insert(avl_t *t, int data)
{

    avl_t *p = (avl_t *)malloc(sizeof(avl_t));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    p->height = 0;

    if (t == NULL) return p;

    if (data > t->data)
    {
        t->right = insert(t->right, data);
        t->height = update_h(t);
    }

    if (data < t->data)
    {
        t->left = insert(t->left, data);
        t->height = update_h(t);
    }

    if ((is_balance(t) == 0))
    {

        int hl = height(t->left);
        int hr = height(t->right);

        if (hl < hr)
        {
            hl = height(t->right->left);
            hr = height(t->right->right);

            if (hl < hr) return left_rotation(t);

            else{
                t->right = right_rotation(t->right);
                t->height = update_h(t);
                return left_rotation(t);
            }
            
        }
        if (hl > hr)
        {
            hl = height(t->left->left);
            hr = height(t->left->right);
            if (hl > hr) return right_rotation(t);
            else{
                t->left = left_rotation(t->left);
                t->height = update_h(t);
                return right_rotation(t);
            }
            
        }
    }
    return t;
}

avl_t *delete(avl_t *t,int data){

    if(t==NULL) return t; 
    if(data == t->data){
        ///case1
        if(t->left == NULL && t->right == NULL){
            free(t);
            return NULL;
        }
        //case3
        if(t->left != NULL && t->right != NULL){
            int minn = find_min(t->right) ; 
            t->data = minn;
            t->right = delete(t->right,minn); 
            return t; 
        }
        ///case2
        if(t->left != NULL){
            avl_t *next = t->left;
            free(t);
            return next; 
        }
        if(t->right != NULL){
            avl_t *next = t->right;
            free(t);
            return next; 
        }
    }
    else if(data > t->data) t->right = delete(t->right,data) ;
    else if (data < t->data) t->left = delete(t->left,data) ; 
    t->height = update_h(t); 


    if ((is_balance(t) == 0))
    {

        int hl = height(t->left);
        int hr = height(t->right);

        if (hl < hr)
        {
            hl = height(t->right->left);
            hr = height(t->right->right);

            if (hl < hr) return left_rotation(t);

            else{
                t->right = right_rotation(t->right);
                t->height = update_h(t);
                return left_rotation(t);
            }
            
        }
        if (hl > hr)
        {
            hl = height(t->left->left);
            hr = height(t->left->right);
            if (hl > hr) return right_rotation(t);
            else{
                t->left = left_rotation(t->left);
                t->height = update_h(t);
                return right_rotation(t);
            }
            
        }
    }
    t->height = update_h(t); 
    return t;
}
int main(void)
{
    avl_t *t = NULL;
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
            t = delete (t, data);
            break;
        case 3:
            print_tree(t);
            break;
        }
    }
    return 0;
}
