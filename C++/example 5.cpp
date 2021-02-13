#include <iostream>
#define NUM 1000000007
using namespace std;

int g_m;

long func(int *arr, int sym, int rep, int pos)
{
    long sum = 0;

    if (pos == 1)
    {
        if (arr[sym] == rep)
            return g_m - 1;
        return g_m;
    }

    for (int i = 0; i < g_m; i++)
    {
        if (i == sym)
        {
            if (arr[sym] == rep)
                continue;
            sum += func(arr, sym, rep + 1, pos - 1);
        }
        else
            sum += func(arr, i, 1, pos - 1);
        sum %= NUM;
    }
    return sum;
}

int main()
{
    int n, i;

    long sum = 0;

    cin >> n >> g_m;
    int *arr = new int[g_m];

    for (i = 0; i < g_m; i++)
        cin >> arr[i];


    if (n == 1)
    {
        cout << g_m;
        return 0;
    }


    for (i = 0; i < g_m; i++)
    {
        sum += func(arr, i, 1, n - 1);
        sum %= NUM;
    }

    cout << sum;
    return 0;
}
