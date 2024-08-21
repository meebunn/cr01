#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    char data;
    struct node *next;

}para;

char rev(char x){
  if(x=='}') return '{' ;
  if(x==')') return '(';
  if(x==']') return '[';
  

  return  x;
}

para *create(para *s){
    char x;
    para *p;
    scanf(" %c",&x);
    p=(para*)malloc(sizeof(para));
    p->data =x;
    p->next =s;

    if(s==NULL) return p;

    if(s->data == rev(x)&& s->data != x){
        s=s->next;
        free(p);
    }
    else{
        s=p;
    }
    return s;
}

int main(){
    para *s = NULL;
    int rob,i;
    char prt;
    scanf("%d",&rob);

    for(i=0;i<rob;i++){
         s= create(s);
    }
    if(s==NULL) printf("1");
    else printf("0");
    
}