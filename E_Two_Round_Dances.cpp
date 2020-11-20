#include <iostream>
#include <algorithm>
#include <list>
#include <map>
#include <vector>
#include <math.h>
using namespace std;
#define ll long long

unsigned ll factorial(unsigned ll n);
int main()
{
    ll n;
    cin >> n;
    ll facn = factorial(n);
    ll facnd2 = factorial(n/2);
    ll facnm1 = factorial(n/2-1);
    ll N = facn/(facnd2*n/2); // number of dances
    ll res = N * facnm1 / 2;
    cout << res << endl;
}

unsigned ll factorial(unsigned ll n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}