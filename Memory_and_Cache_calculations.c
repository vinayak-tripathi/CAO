#include<stdio.h>
#include<math.h>
int main(){
    int option;
    unsigned long long int cache, main, line, block;
    printf("Enter Main memory size(in G): ");
    scanf("%llu", &main);
    printf("Enter Cache memory size(in K): ");
    scanf("%llu", &cache);
    printf("Enter Block size(in word): ");
    scanf("%llu", &block);
    line=block;
    printf("Enter the type of mapping:\n  1 for Direct Mapping\n  2 for Two Set Way Associative Mapping\n");
    scanf("%d",&option);
    if (option==1){
        printf("\n*******Direct Mapping*******");
        printf("\nMain memory size is %llu G", main);
        printf("\nCache memory size is %llu K", cache);
        unsigned long long int add_bus=log2(main*1024*1024*1024);
        unsigned long long int add_for_word=log2(block);
        unsigned long long int blocks_in_main= main*1024*1024*1024/block;
        unsigned long long int add_bus_for_blocks=log2(blocks_in_main);
        unsigned long long int add_bus_for_cache=log2(cache*1024);
        unsigned long long int lines_in_cache= cache*1024/block;
        unsigned long long int add_bus_for_lines=log2(lines_in_cache);
        unsigned long long int page_size=cache;
        unsigned long long int pages_in_main=main*1024*1024/page_size;
        unsigned long long int add_bus_for_pages=log2(pages_in_main);
        printf("\nAddress Lines required for Main Memory: %llu", add_bus);
        printf("\nBlocks in main memory: %llu",blocks_in_main);
        printf("\nAddress lines required to identify each block in main memory: %llu",add_bus_for_blocks);
        printf("\nAddress Lines required for each bank: %llu", add_bus_for_cache);
        printf("\nLines in Cache memory: %llu", lines_in_cache);
        printf("\nPage Size in Main Memory: %llu K", page_size);
        printf("\nNumber of pages in Main memory: %llu",pages_in_main);
        printf("\nAddress Lines required to identify each Word in block: %llu", add_for_word);
        printf("\nAddress lines required to identify each block in main memory or each line in cache: %llu", add_bus_for_lines);
        printf("\nAddress lines required to identify each page in Main memory: %llu \n\n",add_bus_for_pages);
    }
    else if(option==2){
        printf("\n*******Two Way Set Associative Mapping*******");
        printf("\nMain memory size is %llu G", main);
        printf("\nCache memory size is %llu K", cache);
        unsigned long long int add_bus=log2(main*1024*1024*1024);
        unsigned long long int add_for_word=log2(block);
        unsigned long long int blocks_in_main= main*1024*1024*1024/block;
        unsigned long long int add_bus_for_blocks=log2(blocks_in_main);
        unsigned long long int size_bank=cache/2;
        unsigned long long int add_bus_for_cache=log2(size_bank*1024);
        unsigned long long int lines_in_cache= size_bank*1024/block;
        unsigned long long int add_bus_for_lines=log2(lines_in_cache);
        unsigned long long int page_size=size_bank;
        unsigned long long int pages_in_main=main*1024*1024/page_size;
        unsigned long long int add_bus_for_pages=log2(pages_in_main);
        printf("\nAddress Lines required for Main Memory: %llu", add_bus);
        printf("\nBlocks in main memory: %llu",blocks_in_main);
        printf("\nAddress lines required to identify each block in main memory: %llu",add_bus_for_blocks);
        printf("\nSize of Bank in cache memory(Bank A & Bank B): %llu K",size_bank);
        printf("\nAddress Lines required for each bank: %llu", add_bus_for_cache);
        printf("\nLines in bank A and bank B: %llu", lines_in_cache);
        printf("\nPage Size in Main Memory: %llu K", page_size);
        printf("\nNumber of pages in Main memory: %llu",pages_in_main);
        printf("\nAddress Lines required to identify each Word in block: %llu", add_for_word);
        printf("\nAddress lines required to identify each block in main memory or each line in both banks A & B: %llu", add_bus_for_lines);
        printf("\nAddress lines required to identify each page in Main memory: %llu\n\n",add_bus_for_pages);
    }
    else{
        printf("Wrong Input!!!\n");
    }
    getch();
    return 0;
}