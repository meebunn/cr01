#include <stdio.h>
#include <stdlib.h>

typedef struct pp {
    float value ; 
    struct pp *next;
}node;

node *creat(node *s, float value){
    node*p;
    p=(node*)malloc(sizeof(node));
    p->value = value;
    p->next = s ;
    if (s== NULL)return p;
    s=p;
    return s;
}
void show(node *s){
    while(s!=NULL){
        printf("%.2lf",s->value);
        s=s->next;
        
    }
}

node *plus(node *s){
    node*head = s;
    node*pre  = s->next ;
    pre->value = pre->value + s->value ;
    s=s->next;
    free(head);
    return s;
}
node *subst(node *s){
    node*head = s;
    node*pre  = s->next ;
    pre->value = pre->value - s->value ;
    s=s->next;
    free(head);
    return s;
}

node *koon(node *s){
    node*head = s;
    node*pre  = s->next ;
    pre->value = pre->value * s->value ;
    s=s->next;
    free(head);
    return s;
}
node *han(node *s){
    node*head = s;
    node*pre  = s->next ;
    pre->value = pre->value / s->value ;
    s=s->next;
    free(head);
    return s;
}
int main(){
    int rob,i;
    char inp ;
    float value ; 
    node *s=NULL ;
    scanf("%d",&rob);
    for(i=0;i<rob;i++){
        scanf(" %c",&inp);
        value = (float)inp-48 ; 

        if(inp == '+'){
            s = plus(s);
        }
        else if( inp == '-'){
            s = subst(s);
        }
        else if( inp == '*'){
            s = koon(s);
        }
        else if( inp == '/'){
            s = han(s);
        }
        else{
            s = creat(s,value);
        }
    }   
    //// printf("%.2lf",s->value);
    show(s);
}