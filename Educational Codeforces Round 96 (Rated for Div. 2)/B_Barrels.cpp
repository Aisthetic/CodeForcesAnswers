#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

int main(){
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        if(n<=1){
            cout << "0" << endl;
        }
        ll k; cin >> k;
        k++;
        ll* elements = new ll[n];
        ll i = 0;
        while(i<n){
            cin >> elements[i];
            i++;
        }
        sort(elements, elements+n);
        ll sum = 0;
        for(ll j = 0; j < k; j++)    
            sum += elements[n-j-1];
        cout << sum << endl;
    }
    return 0;
}