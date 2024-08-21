#include <stdio.h>
#include <stdlib.h>
typedef struct countgame
{
    int shot;
    struct countgame *next ; 
}CGM ;

CGM *creatnode(CGM *startnode){
    int num;
    CGM *p,*head=startnode; 
    scanf("%d",&num);
    p = (CGM *)malloc(sizeof(CGM));
    p->shot = num ;
    p->next = NULL ; 
    if(startnode == NULL) return p ;
    else{
        while(startnode->next!=NULL){
            startnode =startnode->next;
        }
        startnode->next = p;
    }
    return head ;

}
void show(CGM *p){
    
    for(int i = 0 ; i< 5;i++){
        printf("%d ", p->shot);
        p = p->next;
    }
    
}

CGM *creatCIR(CGM *startnode){
    CGM *head=startnode;
    while(startnode->next!=NULL){
        startnode = startnode->next;
    }
    startnode->next = head ;
    return head ;
}

int lekdod(int count , int num){
    int i;
    while(count>0){
        if(count%10==num) return 1 ;
        count/10 ;
    }
    return 0 ;
}


int main(){
    CGM *startnode,*prev;
    int player,num,i,count=1;
    startnode = NULL;
    scanf("%d %d",&player,&num);
    for(i=0;i<player;i++){
        startnode = creatnode(startnode);
    }
    startnode = creatCIR(startnode);/// circle
    prev = NULL;
    while(prev->next != prev)
        if((count%num==0 || lekdod(count,num)== 1)&&startnode->shot!=0){
            startnode->shot -=1 ;
            if(startnode->shot <0){
                prev->next = startnode->next ;
            }
            prev = startnode;
            startnode = startnode->next ;
            count+=1
        }
        else{
            prev = startnode ;
            startnode =startnode->next ;
            count+=1
        }
    }
    show(startnode);
}