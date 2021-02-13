#include <iostream>

using namespace std;

int main()
{
    int d, i;

    cin >> d;
    int *x = new int[d];

    for (i = 0; i < d; i++)
    {
        long a, b;
        cin >> a >> b;
        if ((a % 2) || (b % 2))
            x[i] = 0;
        else if ((a % 4 == 0) || (b % 4 == 0))
            x[i] = 2;
        else
            x[i] = 1;
    }

    for (i = 0; i < d; i++)
    {
        if (x[i] == 0)
            cout<<"mecem\n";
        else if (x[i] == 1)
            cout<<"ozi\n";
        else
            cout<<"yes\n";
     }

    return 0;
}
