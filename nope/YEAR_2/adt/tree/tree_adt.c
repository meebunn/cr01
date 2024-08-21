#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int level;
    int value;
    struct node *next_sibling; 
    struct node *first_child;
} node_t;
typedef node_t tree_t;
typedef struct node2{
    int data;
    struct node2 *next;
} node_t2;
typedef node_t2 queue_t;

int search(tree_t *t ,int value){
  int v1,v2;
  if(t == NULL) return 0 ;
  if(t->value == value) return 1;
  v1 = search(t->first_child,value);
  v2 = search(t->next_sibling,value); 
  return v1 || v2 ; 
  
}

tree_t * search_pst(tree_t *t ,int value){
  tree_t *pos=NULL ; 
  if(t == NULL) return t ;
  if(t->value == value) return t ;
  pos = search_pst(t->first_child,value);
  if(pos!=NULL) return pos ; 
  else return search_pst(t->next_sibling,value);
  
}



tree_t *attach(tree_t *t, int parent, int child) {
  tree_t *p = NULL, *pos = NULL, *sb = NULL;
  pos = search_pst(t, parent);
  p = (tree_t *)malloc(sizeof(tree_t));
  if (parent == -1)
    p->level = 0;
  else
    p->level = pos->level + 1;
  p->value = child;
  p->first_child = NULL;
  p->next_sibling = NULL;
  if (parent == -1)
    return p; // root
  else {
    if (pos->first_child == NULL)
      pos->first_child = p;
    else {
      sb = pos->first_child;
      while (sb->next_sibling != NULL) {
        sb = sb->next_sibling;
      }
      sb->next_sibling = p;
    }
  }

  return t;
}

int degree(tree_t *t,int value){
    int check ;
    int sum=0 ;
    tree_t *pos = search_pst(t,value) ;
    if(pos ==NULL) return 0 ;

    if(pos->first_child != NULL) {
        tree_t *sb = pos->first_child ; 
        while(sb->next_sibling != NULL){
            sb = sb->next_sibling ;
            sum+=1;
        }
        sum +=1;
        return sum ; 
    }
    else return 0 ;
    
}

int is_root(tree_t *t, int value) {
  return t->value == value ? 1 : 0 ;
}

int is_leaf(tree_t *t,int value){
  tree_t *pos = search_pst(t,value);
  return pos->first_child == NULL ? 1 : 0 ;
}

queue_t *enqueue(queue_t *s,int num)
{
    queue_t *first = s;
    queue_t *p;

    p = (queue_t *)malloc(sizeof(queue_t));
    p->data = num;
    p->next = NULL;
    if (s == NULL)
    {
        return p;
    }
    while (s->next != NULL)
    {
        s = s->next;
    }
    s->next = p;

    return first;
}

queue_t *dequeue(queue_t *s){
    queue_t *tmp=s;
    if(s==NULL) {
        printf("Queue is empty.\n");
        return s;
    }
    s=s->next;
    free(tmp);
    return s;

}

void bfs(tree_t *t){
  queue_t *s=NULL;
  tree_t *r;
  s = enqueue(s, t->value);
  while(s!=NULL){
    printf("%d ",s->data);
    r = search_pst(t, s->data);
    if(r->first_child != NULL){
      r=r->first_child ;
      s= enqueue(s,r->value);
      while(r->next_sibling!=NULL){
        r=r->next_sibling ; 
        s=enqueue(s,r->value);
      }
     
    }
   s = dequeue(s);
  }
  printf("\n");
}

void dfs(tree_t *t) {
  if (t == NULL) return ;
  printf("%d ", t->value);
  dfs(t->first_child);
  dfs(t->next_sibling);
  return;
}

tree_t *his_parent(tree_t *t,int value){
  queue_t *s=NULL;
  tree_t *pos,*run ;
  ///if(is_root(t,value) == 1 ) return t ;
  s =enqueue(s,t->value);
  while(s!=NULL){
    pos = search_pst(t,s->data);
    if(pos->first_child != NULL){
      run = pos->first_child ;
      if(run->value == value) return pos ;
      else{
        s = enqueue(s,run->value);
      }
      while(run->next_sibling != NULL) {
        run = run->next_sibling ;
        if(run->value == value ) return pos ;
        else{
          s = enqueue(s, run->value);
        }
        
      }
    }
    s = dequeue(s);
  }
  return t;
}

void siblings(tree_t *t , int value){
  tree_t *pos=NULL,*run=NULL;
  pos = his_parent(t,value);
  run = pos->first_child ;
  if(run->value != value) printf("%d ",run->value);
  while(run->next_sibling != NULL){
    run = run->next_sibling ; 
    if(run->value != value ) printf("%d ",run->value);
  }
  printf("\n");
  
}

int depth(tree_t *t , int value){
  tree_t *pos ; 
  pos = search_pst(t,value);
  return pos->level;
}

 void print_path(tree_t *t,int start,int end){
   tree_t *pos=NULL,*older=NULL; 
   pos= search_pst(t,end);
   older=his_parent(t,pos->value);
   if(start == end) {
     printf("%d ",pos->value);
     return;
   }
   print_path(t,start,older->value);
   printf("%d ",pos->value);
 }

int path_length(tree_t *t,int start,int end){
  tree_t *end_pt, *start_pt ;
  start_pt = search_pst(t,start);
  end_pt = search_pst(t,end);
  return end_pt->level - start_pt->level +1 ;
}

void ancestor(tree_t *t,int value){
  tree_t *pos,*older ; 
  pos = search_pst(t,value);
  if(is_root(t,value) == 1){
    printf("%d ",pos->value);
    return;
  }
  older = his_parent(t,pos->value);
  ancestor(t,older->value);
  printf("%d ",pos->value);
}
void descendant(tree_t *t,int value){
  tree_t *newt=NULL; 
  newt = search_pst(t,value);
  bfs(newt);
  
}

void destroy(tree_t *t){
  if (t != NULL){
    destroy(t->first_child);
    destroy(t->next_sibling);
    free(t);
  }
}

tree_t *detach(tree_t *t, int value) {

  if (t->value == value) {
    destroy(t->first_child);
    free(t);
    return NULL;
  }
  tree_t *s = search_pst(t, value);
  tree_t *parent = his_parent(t,value);
  if (parent->first_child->value != value) {
    tree_t *run = parent->first_child;
    tree_t *dd= NULL;
    while (run->value != value) {
      dd= run;
      run = run->next_sibling;
    }
    dd->next_sibling = run->next_sibling;
  } else {
    parent->first_child = parent->first_child->next_sibling;
  }
  destroy(s->first_child);
  free(s);
  return t;
}

void print_tree(tree_t *t){
  if(t==NULL) return ;
  for(int i = 0 ; i < t->level*4 ; i++){
    printf(" ");
  }
  printf("%d\n",t->value);
  print_tree(t->first_child);
  print_tree(t->next_sibling);
}


int main(void)
{
  tree_t *t = NULL;
  int n, i, command;
  int parent, child, node, start, end;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &command);
    switch (command)
    {
    case 1:
      scanf("%d %d", &parent, &child);
      t = attach(t, parent, child);
      break;
    case 2:
      scanf("%d", &node);
      t = detach(t, node);
      break;
    case 3:
      scanf("%d", &node);
      printf("%d\n", search(t, node));
      break;
    case 4:
      scanf("%d", &node);
      printf("%d\n", degree(t, node));
      break;
    case 5:
      scanf("%d", &node);
      printf("%d\n", is_root(t, node));
      break;
    case 6:
      scanf("%d", &node);
      printf("%d\n", is_leaf(t, node));
      break;
    case 7:
      scanf("%d", &node);
      siblings(t, node);
      break;
    case 8:
      scanf("%d", &node);
      printf("%d\n", depth(t, node));
      break;
    case 9:
      scanf("%d %d", &start, &end);
      print_path(t, start, end);
      break;
    case 10:
      scanf("%d %d", &start, &end);
      printf("%d\n",
             path_length(t, start, end));
      break;
    case 11:
      scanf("%d", &node);
      ancestor(t, node);
      break;
    case 12:
      scanf("%d", &node);
      descendant(t, node);
      break;
    case 13:
      bfs(t);
      break;
    case 14:
      dfs(t);
      break;
    case 15:
      print_tree(t);
      break;
    }
  }
  return 0;
}
