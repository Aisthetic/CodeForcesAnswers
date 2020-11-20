#include <iostream>
#include <algorithm>
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
        if(n == 2){
            cout << "2" << endl;
            cout << "1 2" << endl;
            continue;
        }

        ll *elts = new ll[n+1];
        cout << "2" << endl;
        // Populating the array with ones
        for (ll i = n; i > 0; i--)
            elts[i] = 1;
        for (ll i = n; i > 2; i--){
            if(elts[i] > 1){
                cout << i << " " << i << endl;
                elts[i] == 1;
            }
            elts[i-2]--,elts[i]--;
            elts[i-1]++;
            cout << i-2 << " " << i << endl;
        }
        if(elts[2] > 1){
            cout << "2 2" << endl; 
        }
        delete[] elts;
    }
}