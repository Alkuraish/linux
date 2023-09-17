#include "../lib/tlpi_hdr.h"

extern char **environ;
/* contenst envroments variables current process */

/* alternative method defineing env is int main(int args, char* argv[], char *envp[])*/


int
main(int argc, char *argv[])
{

    char **ep;
    for (ep = environ; *ep != NULL; ep++)
        puts(*ep);


    exit(EXIT_SUCCESS);
}