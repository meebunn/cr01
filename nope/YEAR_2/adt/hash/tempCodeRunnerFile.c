0;
    // Randomly assign integers to memory
    for (i = 0; i < size; i++)
        memory[i] = rand();
    return memory;
}
// Write your code here
// ...
 cache_t *init_cache(int cache_size){
    cache_t *p = (cache_t*)malloc(sizeof(cache_t)) ; 
    p->table = (cell_t*)malloc(sizeof(cell_t)*cache_size) ; 
    p->cache_size = cache_size  ;
    for(int i=0;i<cache_size;i++) {
        p->table[i].data = -1;
        p->table[i].mem_addr = -1 ;
    }
    return p ; 
 }


void get_data(int addr, memory_t *memory,cache_t *cache){
    unsigned int idx =  addr%cache->cache_size ; 

    if(cache->table[idx].data == -1 ){
        printf("Load from memory\n");
        cache->table[idx].data = memory[addr] ; 
        cache->table[idx].mem_addr = addr ; 
    }
    else if(cache->table[idx].data == memory[addr]){
        printf("Address %d is loaded\n",addr) ; 
    }
    else if (cache->table[idx].data != -1 ){
        printf("Index: %d is used\n",idx);
        printf("Load from memory\n") ; 
        cache->table[idx].data = memory[addr] ; 
        cache->table[idx].mem_addr = addr ; 
    }
    
    printf("Data: %d\n",cache->table[idx].data );
}


int main(void)
{
    memory_t *memory = NULL;
    cache_t *cache = NULL;
    int memory_size, cache_size;
    int i, n, addr;
    scanf("%d %d %d", &memory_size,
          &cache_size, &n);
    memory = init_memory(memory_size);
    cache = init_cache(cache_size);
    for (i = 0; i < n; i++)
    {
        printf("Load address: ");
        scanf("%d", &addr);
        get_data(addr, memory, cache);
    }
    return 0;
}