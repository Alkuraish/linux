#ifndef ERROR_FUNCTIONS_H
#define ERROR_FUNCTIONS_H

/* 
The errMsg() function prints the error text corresponding to the current value of errno 
— this consists of the error name, such as EPERM, plus the error description as returned by strerror()—followed 
by the formatted output specified in the argument list.

The errExit() function operates like errMsg(), but also terminates the program,
either by calling exit() or, if the environment variable EF_DUMPCORE is defined with a nonempty string value, 
by calling abort() to produce a core 
dump file for use withb the debugger. (We explain core dump files in Section 22.1.)

The err_exit() function is similar to errExit(), but differs in two respects:
1)It doesn’t flush standard output before printing the error message.
2)It terminates the process by calling _exit() instead of exit(). This causes the pro-
cess to terminate without flushing stdio buffers or invoking exit handlers.

The errExitEN() function is the same as errExit(), except that instead of printing
the error text corresponding to the current value of errno, it prints the text corre-
sponding to the error number (thus, the EN suffix) given in the argument errnum.

The fatal() function is used to diagnose general errors, including errors from
library functions that don’t set errno. Its argument list is the same as for printf(),
except that a terminating newline character is automatically appended to the out-
put string.

The usageErr() function is used to diagnose errors in command-line argument
usage. It takes an argument list in the style of printf() and prints the string Usage:
followed by the formatted output on standard error, and then terminates the pro-
gram by calling exit().

The cmdLineErr() function is similar to usageErr(), but is intended for diagnosing
errors in the command-line arguments specified to a program.
*/


#ifdef __GNUC__
    /* This macro stops 'gcc -Wall' complaining that "control reaches
        end of non-void function" if we use the following functions to
            terminate main() or some other non-void function. */


#define NORETURN __attribute__ ((__noreturn__))
#else
#define NORETURN
#endif

void errMsg(const char *format, ...);
void errExit(const char *format, ...) NORETURN ;
void err_exit(const char *format, ...) NORETURN ;
void errExitEN(int errnum, const char *format, ...) NORETURN ;


void fatal(const char *format, ...) NORETURN ;
void usageErr(const char *format, ...) NORETURN ;
void cmdLineErr(const char *format, ...) NORETURN ;


#endif