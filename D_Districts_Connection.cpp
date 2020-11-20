#include <iostream>
#include <algorithm>
#include <list>
#include <map>
#include <vector>
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
        ll *districts = new ll[n+1];
        int pivot = -1;
        int anti_pivot = -1;
        vector<int> waiting;
        for (size_t i = 1; i < n+1; i++)
        {
            cin >> districts[i];
            if (pivot == -1){
                pivot = i;
                continue;
            }
            else if (anti_pivot == -1 && districts[i] != districts[pivot])
            {
                cout << "YES" << endl;
                anti_pivot = i;
            }

            if (districts[pivot] == districts[i])
            {
                if (anti_pivot == -1)
                    waiting.push_back(i);
                else
                {
                    cout << i << " " << anti_pivot << endl;
                    continue;
                }
            }
            else
            {
                cout << i << " " << pivot << endl;
            }
        }
        if (anti_pivot == -1)
        {
            cout << "NO" << endl;
        }
        else
        {
            for (auto &v : waiting)
            {
                cout << v << " " << anti_pivot << endl;
            }
        }
    }
    return 0;
}