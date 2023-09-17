#include "../lib/tlpi_hdr.h"
#include <stdio.h>

#include <unistd.h>
/* brk, sbrk */
#include <sys/types.h>



int brk(void* end_data_segment);
/* funciton (system call) set programm break to location specified by end_data_segment */
/* return   0 on success or -1 on error */

void *sbrk(intptr_t increment);
/* function (system call) adjust program break by adding  increment to it */
/* return previous program break on success. or (*void) -1 on error */

void* malloc(size_t size);
/* function allocate size bytes from the heap*/
/* return pointer to allocated memory on success, or NULL on error */

void free(void* ptr)
/* function deallocates the block of memory pointed to by its ptr argument */
