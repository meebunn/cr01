#include <stdio.h>
#include <stdlib.h>
typedef struct heap
{
    int *data;
    int last_index;
} heap_t;
// Write your code here
// ...

void bfs(heap_t *heap) {
    for(int i=1 ; i<heap->last_index+1 ; i++){
        printf("%d ",heap->data[i]);
    }
    printf("\n");
}

int find_max(heap_t *heap){
    if(heap->last_index == -1 ) return -1 ;
    return heap->data[1];
}

heap_t *init_heap(int m){
    heap_t *heap = (heap_t*)malloc(sizeof(heap_t));
    heap->data = (int *)malloc(sizeof(int)*(m+1)); 
    for(int i=0;i<m+1;i++) heap->data[i] = 0 ; 
    heap->last_index = -1 ; //empty 
    return heap ; 
}

void insert(heap_t *heap , int data) {
    heap_t *run=heap ; 
    int run = heap->last_index ; 
    if(heap->last_index == -1) { /// empty
        heap->data[1] = data  ;
        heap->last_index = 1 ; 
    }
    else {
        heap->last_index +=1;
        heap->data[heap->last_index]=data  ;
        heap->data[0]  +=1;//// index 0 store max numbers ;
        while(run->data[(run->last_index)/2] < run->data[run->last_index] && run->last_index/2 != 0){
            int swp = run->data[run->last_index/2] ; 
            run->data[run->last_index/2] = run->data[run->last_index]  ;
            run->data[run->last_index] = swp ; 
            run->last_index = run->last_index/2 ;
         
        }
        heap->last_index = heap->data[0];
    }
}


void update_key(heap_t *heap, int old, int new) {
    int i=0; /// index;
    ////update////
    while(1){
        i++ ; 
        if(heap->data[i] == old) {
            heap->data[i] = new ; 
            break;
        }
    }
    int k=i ;
    while( 2 * k <= heap->last_index){
        int p1 = 2*k ;
        int p2 = (2*k)+1 ;
        if(heap->data[k] < heap->data[p1] && heap->data[k] < heap->data[p2]){
            if(heap->data[p1]>heap->data[p2]){
                int swp = heap->data[k] ; 
                heap->data[k] = heap->data[p1];
                heap->data[p1] = swp ; 
                k = p1 ; 
            }
            else {
                int swp = heap->data[k] ; 
                heap->data[k] = heap->data[p2];
                heap->data[p2] = swp ; 
                k = p2 ; 
            }
        }
        
        else if( heap->data[k] < heap->data[p1]){
            int swp = heap->data[k];
            heap->data[k] = heap->data[p1] ; 
            heap->data[p1] =  swp ; 
            k = p1 ; 
        }

        else if ( heap->data[k] < heap->data[p2]){
            int swp = heap->data[k] ; 
            heap->data[k] = heap->data[p2];
            heap->data[p2] = swp ; 
            k = p2 ; 
        }
        else{
            break;
        }
    }

    while (i > 1 && heap->data[i] > heap->data[i / 2]){
        int p= i / 2;
        int tmp = heap->data[i];
        heap->data[i] = heap->data[p];
        heap->data[p] = tmp;
        i = p;
    }


}
void delete_max(heap_t *heap){
    int k =1 ; 
    heap->data[1] = heap->data[heap->last_index] ; 
    heap->data[heap->last_index] = 0 ;
    heap->last_index -= 1 ; 
    heap->data[0] -=1 ; 
    while( 2 * k < heap->last_index){
        int p1 = 2*k ;
        int p2 = (2*k)+1 ;
        if(heap->data[k] < heap->data[p1] && heap->data[k] < heap->data[p2]){
            if(heap->data[p1]>heap->data[p2]){
                int swp = heap->data[k] ; 
                heap->data[k] = heap->data[p1];
                heap->data[p1] = swp ; 
                k = p1 ; 
            }
            else {
                int swp = heap->data[k] ; 
                heap->data[k] = heap->data[p2];
                heap->data[p2] = swp ; 
                k = p2 ; 
            }
        }
        
        else if( heap->data[k] < heap->data[p1]){
            int swp = heap->data[k];
            heap->data[k] = heap->data[p1] ; 
            heap->data[p1] =  swp ; 
            k = p1 ; 
        }

        else if ( heap->data[k] < heap->data[p2]){
            int swp = heap->data[k] ; 
            heap->data[k] = heap->data[p2];
            heap->data[p2] = swp ; 
            k = p2 ; 
        }
    }
}
void delete_max(heap_t * heap){
  
  heap->data[1] = heap->data[heap->last_index] ; 
  heap->last_index --  ;
  
  
}



int main(void)
{
    heap_t *max_heap = NULL;
    int m, n, i;
    int command, data;
    int old_key, new_key;
    scanf("%d %d", &m, &n);
    max_heap = init_heap(m);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &command);
        switch (command)
        {
        case 1:
            scanf("%d", &data);
            insert(max_heap, data);
            break;
        case 2:
            delete_max(max_heap);
            break;
        case 3:
            printf("%d\n", find_max(max_heap));
            break;
        case 4:
            scanf("%d %d", &old_key, &new_key);
            update_key(max_heap, old_key, new_key);
            break;
        case 5:
            bfs(max_heap);
            break;
        }
    }
    return 0;
}
