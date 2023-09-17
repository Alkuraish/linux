#include "../lib/tlpi_hdr.h"
/* for other functions */

#include <unistd.h> 
/* getpid */


#include <stdlib.h>
/* getenv, putenv, setenv, unsetenv, clearenv */

#include <sys/stat.h>
/* standart type UNIX SYS */

pid_t getpid(void); 
/* return PID parent of this process */
    

char *getenv(const char* name);
/* return variable enviroment for this process (if there is no env. variable with current name func return NULL) */

int putenv(const char* string);
/* function modify or create new enviroment varibale (string := (name=value) )*/

int setenv(const char* name, const char* value, int overwrite);
/* alterantive putenv*/

int unsetenv(const char* name);
/* function removes the variable identified by name from the envroment */


int clearenv(void);
/* function erase to entire enviroment */


int main(int args, char* argv[]) {
    printf("%d\n", getpid());
    

    printf("%s\n", getenv("PATH")); 




    exit(EXIT_SUCCESS);
}
    