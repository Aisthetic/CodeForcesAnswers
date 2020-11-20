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
        int max = -1;
        int *fish = new int[n];
        for (size_t i = 0; i < n; i++)
        {
            cin >> fish[i];
            if (fish[i] > max)
                max = fish[i];
        }
        for (size_t i = 0; i < n; i++)
        {
            int f = fish[i];
            if (fish[i] == max)
            {
                auto t1 = (i != 0 && fish[i] != fish[i - 1]);
                auto t2 = (i != n && fish[i] != fish[i + 1]);
                if ((i != 0 && fish[i] != fish[i - 1]) || (i != n - 1 && fish[i] != fish[i + 1]))
                {
                    cout << i + 1 << endl;
                    break;
                }
            }
            if (i == n - 1)
            {
                cout << -1 << endl;
                break;
            }
        }
    }
}