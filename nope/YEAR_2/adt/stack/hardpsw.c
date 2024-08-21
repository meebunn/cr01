#include <stdio.h>
#include <stdlib.h>
typedef struct pswd{
    char data;
    struct pswd *next;
}pass;

pass *createX(pass *s,char x){
    pass *p;
    p=(pass*)malloc(sizeof(pass));
    p->data = x;
    p->next = s;

    if(s==NULL) return p ;

    s=p;
    return s;
}   

int main(){
    pass *s;
    char inp1,inp2;
    int n=1,x=0,y=0;
    while(1){
        scanf(" %c",&inp1);
        if(inp1 == 'x') break;
        s= createX(s,inp1);
        x++;

    }
    while(1){
        scanf(" %c",&inp2);
        if(inp2 == 'y')break;

        if(s->data == inp2){
            s=s->next;
            y++;
        }
        else{
            n=0;
            break;
        }
    }
    if(x!=y) n=0;
    printf("%d",n);

    
}