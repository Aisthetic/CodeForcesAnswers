#include <iostream>
#include <algorithm>
#include <list>
#include <math.h>
using namespace std;
#define ll long long

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        int last1 = -1, cnt = 0;
        char current;
        for (int i = 0; i < n; i++)
        {
            cin >> current;
            if (current == '1'){
                if (last1 != -1 && last1 != i - 1)
                    cnt += i - last1 - 1;
                last1 = i;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}