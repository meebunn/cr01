#include <stdio.h>
#include <stdlib.h>
#include "week8.h"

#ifndef __bin_tree__
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node_t;
typedef node_t tree_t;
#endif
// Write your code here
// ** Note that the attach() function has // been implemented already and included // in the week8.h header
// ...
int depth(tree_t *t) {
  if (t == NULL) return -1; 
  int num_l = depth(t->left);
  int num_r = depth(t->right);
  if (num_l > num_r) return num_l + 1;
  return num_r + 1;
}

int is_full(tree_t *t){
    if(t==NULL) return 1;
    if(t->left == NULL && t->right == NULL) return 1;
    if(t->left != NULL && t->right == NULL) return 0 ;
    if(t->left == NULL && t->right != NULL) return 0 ;

    return 1 &&is_full(t->left)&& is_full(t->right) ;

}
int is_perfect(tree_t *t){
    int nl=0,nr=0;
    tree_t *runL = t;
    tree_t *runR = t;
    if(t==NULL)return 1;
    if(t->left == NULL && t->right == NULL) return 1 ;
    if(depth(t->left) != depth(t->right)) return 0 ;
    while(runL->left!= NULL){
        nl +=1;
        runL = runL->left; 
    }
    while(runR->right!= NULL){
        nr +=1;
        runR = runR->right; 
    }

    if( nl == nr && is_full(t) == 1) return 1;
    else return  0; 
}

int is_degenerate(tree_t *t){
    if(t==NULL) return 1; 
    if(t->left == NULL && t->right == NULL) return 1; 
    if(t->left != NULL && t->right != NULL) return 0 ;
    if(t->left != NULL) return 1 && is_degenerate(t->left);
    if(t->right != NULL) return 1 && is_degenerate(t->right);     
}

int is_skewed(tree_t *t){
    tree_t *runL =t , *runR = t ;
    if(t==NULL) return 1;
    if(is_degenerate(t) == 1){
        ////printf("enter func\n");
        if(t->left !=NULL){
            ////printf("in left\n");
            while(runL!=NULL){
                ////printf("in while\n");
                runL = runL->left ; 
                if(runL == NULL) return 1 ;
                if(runL->right != NULL) return 0;
            }
        }
        else if(t->right != NULL){
            while(runR!=NULL){
                runR = runR->right ;
                if(runR == NULL) return 1 ;
                if(runR->left != NULL) return 0 ; 
            }
        }
    }
    else return 0 ;
    printf("%d" ,runL);
    
}

int is_complete(tree_t *t) {
  if (t == NULL) return 1;
  if(is_perfect(t) == 1) return 1;
  tree_t *runL_tree = t->left;
  tree_t *runR_tree = t->right;
  if (depth(runL_tree) - 1 == depth(runR_tree)) {
    if (is_complete(runL_tree) && is_perfect(runR_tree)) return 1;
    return 0;
  }
  if (depth(runL_tree) == depth(runR_tree)) {
    if (is_perfect(runL_tree) && is_complete(runR_tree)) return 1;

    if(t->left != NULL && t->right == NULL)return 1;

    return 0;
  }
  return 0;
}

int main(void)
{
    tree_t *t = NULL;
    int n, i;
    int parent, child;
    int branch; // 0 root, 1 left, 2 right
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &parent, &child, &branch);
        t = attach(t, parent, child, branch);
    }

    printf("%d %d %d %d %d\n", is_full(t), is_perfect(t),is_complete(t), is_degenerate(t), is_skewed(t));
    return 0;
}
