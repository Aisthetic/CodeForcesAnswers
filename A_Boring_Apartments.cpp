#include <iostream>
#include <algorithm>
#include <list>
#include <math.h>
using namespace std;
#define ll long long

int numberOfDigits(ll);
int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        int nbDigs =  numberOfDigits(n);
        int type = n % 10;
        int cnt = 0;
        for(int i = 1; i < type + 1; i ++){
            int nb = i;
            for(int j = 1; j < 5; j++){
                if((i==type && nb <= n) || (i!=type && nb < 10000)){
                    cnt += j;
                    auto pw = pow(10,j)*i;
                    nb += pw;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

int numberOfDigits(ll n){
    for(int i = 0; i < n; i++)
        if(n < pow(10,i))
            return i;
    return 1;
}