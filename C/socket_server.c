#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdlib.h>
#include <unistd.h>

#define ADDRESS     "mysocket"  /* addr to connect */

char *strs = "This is the string from the server.\n";

int main(){
    char c; FILE *fp;int fromlen;
    register int i, s, ns, len;
    struct sockaddr_un saun, fsaun;
    int result;
    /* create a UNIX domain stream socket */
    s = socket(AF_UNIX, SOCK_STREAM, 0);
    saun.sun_family = AF_UNIX;
    strcpy(saun.sun_path, ADDRESS);
    unlink(ADDRESS); /*unlink (rm) ADDRESS to bind won’t fail */
    len = sizeof(saun.sun_family) + strlen(saun.sun_path);
    result = bind(s, &saun, len);/*bind the address to the socket */
    result = listen(s, 5); /* listen on the socket */
    ns = accept(s, &fsaun, &fromlen); /* Accept a connection */
    fp = fdopen(ns, "r"); /* open the connection */
    /* send the string to the client */
    send(ns, strs, strlen(strs), 0);
    /* read from the server */
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
        if (c == '\n') break;
    }
    close(s);
    exit(0);
}
