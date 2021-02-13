#include <iostream>

#define NUM 100000

using namespace std;

int main()
{
    int o[NUM]{0}, l[NUM][2]{0}, u[NUM]{0};
    int o_size, l_size, u_size, i, tmp, sum;

    cin >> o_size >> l_size >> u_size;
    for (i = 0; i < o_size; i++)
    {
        cin >> tmp;
        ++o[tmp - 1];
    }

    for (i = 0; i < l_size; i++)
    {
        cin >> tmp;
        ++l[tmp - 1][0];
    }

    for (i = 0; i < u_size; i++)
    {
        cin >> tmp;
        ++u[tmp - 1];
    }

    i = NUM - 2;

    while (u[i] == 0)
        --i;
    --i;

    for ( ; i >= 0; i--)
        l[i][1] = l[i + 1][1] + u[i + 1];

    for (i = 0; i < NUM && l[i][1]; i++)
        u[i] = l[i][0] * l[i][1];
    u[i] = 0;

    i -= 2;

    while (i >= 0)
    {
        u[i] += u[i + 1];
        --i;
    }

    sum = 0;
    for (i = 0; i < NUM && u[i + 1]; i++)
        sum += o[i] * u[i + 1];
    cout << sum;
    return 0;
}
