#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>
#include <unistd.h>

#define ADDRESS     "mysocket"  /* addr to connect */

char *strs = "This is the first string from the client.\n";

int main(){
    char c; FILE *fp; register int i, s, len;
    struct sockaddr_un saun;
    int result;
    /* create a UNIX domain stream socket */
    s = socket(AF_UNIX, SOCK_STREAM, 0);
    saun.sun_family = AF_UNIX;
    strcpy(saun.sun_path, ADDRESS);

    len = sizeof(saun.sun_family) + strlen(saun.sun_path);
    result= connect(s, &saun, len);
    fp = fdopen(s, "r");

    /* read from the server */
    while ((c = fgetc(fp)) != EOF) {
       putchar(c);
       if (c == '\n') break;
    }
    /* Now we send some strings to the server.*/
    send(s, strs, strlen(strs), 0);
    close(s);
    exit(0);
}
