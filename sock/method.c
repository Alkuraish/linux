#include "../lib/tlpi_hdr.h"
#include <sys/socket.h>



int socket(int domain, int type, int protocol);
/* Returns file descriptor on success, or –1 on error */
/*
The domain argument specifies the communication domain for the socket. The type
argument specifies the socket type. This argument is usually specified as either
SOCK_STREAM, to create a stream socket, or SOCK_DGRAM, to create a datagram socket.
The protocol argument is always specified as 0 for the socket types we describe in
this book. Nonzero protocol values are used with some socket types that we don’t
describe. For example, protocol is specified as IPPROTO_RAW for raw sockets (SOCK_RAW). 
*/

int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
/*  Returns 0 on success, or –1 on error */
/*
The sockfd argument is a file descriptor obtained from a previous call to socket(). The
addr argument is a pointer to a structure specifying the address to which this socket
is to be bound. The type of structure passed in this argument depends on the
socket domain. The addrlen argument specifies the size of the address structure.
The socklen_t data type used for the addrlen argument is an integer type specified
by SUSv3.
*/


struct sockaddr {
    sa_family_t sa_family;              /* Address family (AF_* constant) */
    char sa_data[14];                   /* Socket address (size varies according to socket domain) */
};



int listen(int sockfd, int backlog);
/* Returns 0 on success, or –1 on error */
/* 
The kernel must record some information about each pending connection request
so that a subsequent accept() can be processed. The backlog argument allows us to
limit the number of such pending connections. Connection requests up to this limit
succeed immediately. (For TCP sockets, the story is a little more complicated, as we’ll
see in Section 61.6.4.) Further connection requests block until a pending connection
is accepted (via accept()), and thus removed from the queue of pending connections.
SUSv3 allows an implementation to place an upper limit on the value that can
be specified for backlog, and permits an implementation to silently round backlog
values down to this limit. SUSv3 specifies that the implementation should advertise
this limit by defining the constant SOMAXCONN in <sys/socket.h>. On Linux, this con-
stant is defined with the value 128. However, since kernel 2.4.25, Linux allows this
limit to be adjusted at run time via the Linux-specific /proc/sys/net/core/somaxconn
file. (In earlier kernel versions, the SOMAXCONN limit is immutable.)
*/



int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
/* Returns file descriptor on success, or –1 on error */
/*
The accept() system call accepts an incoming connection on the listening stream
socket referred to by the file descriptor sockfd. If there are no pending connections
when accept() is called, the call blocks until a connection request arrives.
*/



int connect(int sockfd, const struct sockaddr *addr, socklen_t *addrlen);
/* Returns 0 on success, or –1 on error */
/*
The connect() system call connects the active socket referred to by the file descriptor
sockfd to the listening socket whose address is specified by addr and addrlen.
*/





ssize_t recvfrom(int sockfd, void *buffer, size_t lenght, int flags, 
                    struct sockaddr *src_addr, socklen_t *addrlen);
/* Returns number of bytes received, 0 on EOF, or –1 on error */
ssize_t sendto(int sockfd, const void *buuffer, size_t lenght, int flags,
                const struct sockaddr *dest_addr, socklen_t addrlen);
/* Returnns number of bytes sent, or  -1 on error */

/*
The return value and the first three arguments to these system calls are the same as
for read() and write().

The fourth argument, flags, is a bit mask controlling socket-specific I/O fea-
tures. We cover these features when we describe the recv() and send() system calls in
Section 61.3. If we don’t require any of these features, we can specify flags as 0.
The src_addr and addrlen arguments are used to obtain or specify the address of
the peer socket with which we are communicating.

For recvfrom(), the src_addr and addrlen arguments return the address of the
remote socket used to send the datagram. (These arguments are analogous to the addr
and addrlen arguments of accept(), which return the address of a connecting peer
socket.) The src_addr argument is a pointer to an address structure appropriate to
the communication domain. As with accept(), addrlen is a value-result argument.
Prior to the call, addrlen should be initialized to the size of the structure pointed to by
src_addr; upon return, it contains the number of bytes actually written to this structure.

If we are not interested in the address of the sender, then we specify both
src_addr and addrlen as NULL. In this case, recvfrom() is equivalent to using recv() to
receive a datagram. We can also use read() to read a datagram, which is equivalent
to using recv() with a flags argument of 0.

Regardless of the value specified for length, recvfrom() retrieves exactly one mes-
sage from a datagram socket. If the size of that message exceeds length bytes, the
message is silently truncated to length bytes.

For sendto(), the dest_addr and addrlen arguments specify the socket to which the
datagram is to be sent. These arguments are employed in the same manner as the
corresponding arguments to connect(). The dest_addr argument is an address struc-
ture suitable for this communication domain. It is initialized with the address of the
destination socket. The addrlen argument specifies the size of addr.
*/




int main(int argc, char** argv);

