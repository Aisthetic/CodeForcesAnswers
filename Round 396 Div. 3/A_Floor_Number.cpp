#include <iostream>
using namespace std;

int main()
{
    int t, n, x, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        if (n <= 2)
        {
            cout << 1 << endl;
            continue;
        }
        k = (int)((n + 2*x - 3) / x);
        cout << k << endl;
    }
    return 0;
}