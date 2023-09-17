#include "./lib/tlpi_hdr.c"
#include <stdio.h>
#include <stdarg.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/un.h>


const char* path = "/tmp/socket";

struct sockaddr {
    sa_family_t sa_family;
    char        sa_data[14];
};


int socket(int domain, int type, int protocol);                                 /* Return 0 on succes, -1 on error */
int bind(int sockfd, const struct sockaddr* addr, socklen_t addrlen);           /* Return 0 on succes, -1 on error */

int listen(int sockfd, int backlog);                                            /* Return 0 on succes, -1 on error */

int accpet(int sockfd, struct sockaddr *addr, socklen_t *addrlen);              /* Return files descriptor on succes, or -1 on error */





int main(int args, char** argv) {

    int des = socket(AF_UNIX, SOCK_STREAM, 0);

    struct sockaddr addr;

    strcpy(path, addr.sa_data, sizeof(sa_data) - 1);

    bind(des, &addr, sizeof(addr));    


    

    return 0;
}