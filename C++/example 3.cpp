#include <iostream>

using namespace std;

int main()
{
    long t, i;
    cin >> t;
    long *arr = new long[t];

    for (i = 0; i < t; i++)
        cin >> arr[i];

    for (i = 0; i < t; i++)
        cout << 3 * (arr[i] + 1) * (arr[i] + 1) / 2 - 9 << '\n';

    return 0;
}
