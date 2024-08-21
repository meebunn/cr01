#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node_t;
typedef node_t queue_t;

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
    printf("%d\n",tmp->data);
    free(tmp);
    return s;

}
void show(queue_t *s){
    if(s==NULL) printf("Queue is empty.\n");
    else{
        while(s->next != NULL){
            printf("%d ",s->data);
            s=s->next;
        }
        printf("%d\n",s->data);
    }
}
void empty(queue_t *s){
    if(s==NULL) printf("Queue is empty.\n");
    else printf("Queue is not empty.\n");

}

void size(queue_t *s){
    int n=0;
    if(s==NULL) printf("%d\n",n);
    else{
        n++;

    while(s->next != NULL){
        s=s->next;
        n++;
    }

    printf("%d\n",n);
    
    }
}
int main(void)
{
    queue_t *q = NULL;
    int n, i, command, value;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &command);
        switch (command)
        {
        case 1:
            scanf("%d", &value);
            q = enqueue(q, value);
            break;
        case 2:
            q = dequeue(q);
            break;
        case 3:
            show(q);
            break;
        case 4:
            empty(q);
            break;
        case 5:
            size(q);
            break;
        }
    }
    return 0;
}
