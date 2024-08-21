#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node_t;

node_t *append(node_t *startNode)
{
    int num;
    node_t *first = startNode;
    node_t *p;
    scanf("%d", &num);

    p = (node_t *)malloc(sizeof(node_t));
    p->data = num;
    p->next = NULL;
    if (startNode == NULL)
    {
        return p;
    }
    while (startNode->next != NULL)
    {
        startNode = startNode->next;
    }
    startNode->next = p;

    return first;
}
void get(node_t *startNode)
{
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        startNode = startNode->next;
    }
    printf("%d\n", startNode->data);
}

node_t *reverse(node_t *startNode)
{
    node_t *pre = NULL;
    node_t *cur = startNode;
    node_t *next_node = NULL;

    while (cur != NULL)
    {
        next_node = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next_node;
    }

    return pre;
}
void show(node_t *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

node_t *cut(node_t *startNod)
{
    int n1, n2, i;
    node_t *head = startNod;
    scanf("%d %d",&n1,&n2);

    for(i=0;i<n1;i++){
        head = startNod->next;
        startNod = startNod->next;
    }
    for(i=0;i<n2-n1;i++){
        startNod = startNod->next;
    }
    startNod->next = NULL;
    return head;
}

int main(void)
{
    node_t *startNode;
    int n, i;
    char command;
    startNode = NULL;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf(" %c", &command);
        switch (command)
        {
        case 'A':
            startNode = append(startNode);
            break;
        case 'G':
            get(startNode);
            break;
        case 'R':
            startNode = reverse(startNode);
            break;
        case 'S':
            show(startNode);
            break;
        case 'C':
            startNode = cut(startNode);
            break;
        }
    }
    return 0;
}
