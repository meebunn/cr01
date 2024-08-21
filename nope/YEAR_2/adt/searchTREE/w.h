avl_t *right_rotate(avl_t *t){
    avl_t *head =t;
    avl_t *new = t->left;
    head->left = new->right ; 
    new->right = head ; 
    head->height = update_h(head);
    new->height = update_h(new); 

    return new ; 
}

avl_t *left_rotate(avl_t*t){
    avl_t *head = t ;
    avl_t *new = t->right ; 
    head->right = new->left ; 
    new->left = head ; 
    head->height = update_h(head);
    new->height = update_h(new);
    return new ; 

}