#include <iostream>
#include <sys/socket.h>
#include <poll.h>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>

#define PIPE(fd) socketpair(AF_UNIX, SOCK_STREAM, PF_UNIX, fd)

using namespace std;

struct pollfd a[2];
nfds_t x;



int main()
{

    int fd[2];

    /*cout<<"Sleeping...\n";
    for( int i = 2 ; i > 0 ; i-- )
    {
        cout<<i<<" seconds to wake up!\n";
        sleep(1);
    }*/

    PIPE(fd);

    if(fork())
    {
        cout<<"Parent..\n";
        close(fd[1]);
        int soc = fd[0];

        char buf[100];
        write(soc, "5", 2);
        read(soc, buf, sizeof(buf));
        cout<<buf<<" hem de burada\n";

        close(soc);
        cout<<"Parent has done its job\n";
        wait(NULL);
    }
    else
    {
        cout<<"Child..\n";
        close(fd[0]);
        int soc = fd[1];
        int x;

        int val = dup(1);
        dup2(soc, 1);
        dup2(soc, 0);

        cin>>x;
        cout<<"This text is being sent"<<flush;


        close(soc);

        dup2(val, 1);
        cout<<"Child is done x = "<<x<<'\n';
    }
    exit(0);
}
