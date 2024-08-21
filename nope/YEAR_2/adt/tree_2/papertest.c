7 
-1 10 0 
10 6 1 
10 18 2 
6 4 1 
6 8 2 
18 21 2 
18 15 1


5 
-1 1 0 
1 2 1 
1 3 2 
2 4 1 
2 5 2
int is_perfect(tree_t *t){
    int nl=0,nr=0;
    tree_t *runL = t;
    tree_t *runR = t;
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
