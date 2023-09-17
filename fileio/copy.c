#include "../lib/tlpi_hdr.h"
#include <fcntl.h>
#include <stdarg.h>
#include <sys/stat.h>


#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif


int 
main(int args, char* argv[]) 
{
    int inputFd, outputFd, openFlags;
    mode_t filePerm;
    ssize_t numRead;
    char buf[BUF_SIZE];
    
    /* Open inpuit and output files */

    if (args != 2 || strcmp(argv[1], "--help")) 
        usageErr("%s old-file new line \n", argv[0]);

    inputFd = open(argv[1], O_RDONLY);
    if (inputFd == -1)
        errExit("opening file %s", argv[1]);
    
    openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    filePerm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |S_IROTH | S_IWOTH;
    outputFd = open(argv[2], openFlags, filePerm);
    if (outputFd == -1)
        errExit("opening file %s", argv[2]);
    
    /* Transfer data until we encouter end of input or an error */

    while( (numRead = read(inputFd, buf, BUF_SIZE)) > 0)
        if (write(outputFd, buf, numRead) != numRead)
            fatal("couldn't write whole buffer ");
    if  (numRead == -1)
        errExit("read");
    
    if (close(inputFd) == -1)
        errExit("close input");
    if (close(outputFd) == -1)
        errExit("close output");

    exit(EXIT_SUCCESS);
}