#include "../lib/tlpi_hdr.h"

#include <stdlib.h>


/* The program in Listing 7-1 can be used to illustrate the effect of free() on the pro-
gram break. This program allocates multiple blocks of memory and then frees
some or all of them, depending on its (optional) command-line arguments.

The first two command-line arguments specify the number and size of blocks to
allocate. The third command-line argument specifies the loop step unit to be used
when freeing memory blocks. If we specify 1 here (which is also the default if this
argument is omitted), then the program frees every memory block; if 2, then every
second allocated block; and so on. The fourth and fifth command-line arguments
specify the range of blocks that we wish to free. If these arguments are omitted, then
all allocated blocks (in steps given by the third command-line argument) are freed.*/

#define MAX_ALLOCS 100000

int main(int args, char** argv) {

    if (args < 2 || args > 6)
        cmdLineErr("Amount command-line argument not suitable\n");
    
    printf("Initial value of program break %10p\n", sbrk(0));

    int alloc_number_block, alloc_size_block;

    alloc_number_block = atoi(argv[1]);
    alloc_size_block   = atoi(argv[2]);

    char* ptr_alloc[MAX_ALLOCS];

    for (int i = 0; i < alloc_number_block; ++i) 
        ptr_alloc[i] = malloc(alloc_size_block);

    printf("Amount bytes was allocted: %d\n", alloc_number_block * alloc_size_block);

    printf("Value of program break after allocation memory: %10p\n", sbrk(0));

    int lower_range    = (args >= 4) ? atoi(argv[4]) : 1;
    int high_range     = (args >= 5) ? atoi(argv[5]) : alloc_number_block;

    printf("Parameters for deallocation step: %d, begin index: %d, end index: %d \n", step_unit, lower_range, high_range);
                    
    for (int i = lower_range - 1; i < high_range; i+=step_unit) {
        free(ptr_alloc[i]);
    }

    printf("Value of prgram break after deallocation memory: %10p \n", sbrk(0));
