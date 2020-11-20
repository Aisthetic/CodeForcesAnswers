#include <iostream>
#include <array>
#include <vector>
#include <math.h>
#include <tuple>
#include <map>
#include <algorithm>
#define ll long long 
using namespace std;

int main()
{
    ll n;
    cin >> n;
    map<ll, ll> lastPosition;
    ll* elements = new ll[n];
    ll count = 0;
    // Reading first element
    ll ele;
    cin >> ele;
    elements[0] = ele;
    lastPosition[elements[0]] = 0;
    ll l = 0;
    ll r = n;
    // Read other elements
    ll i = 1;
    bool specialCase;
    bool hasZeros = false;
    while (i<n)
    {
        ll ai, newL, newR;
        specialCase = false;
        cin >> ai;
        // Cumulative sum
        elements[i] = elements[i-1] + ai;
        newR = i;
        // Checking if element == 0
        if (elements[i] == 0){
            newL = 0;
            hasZeros = true;
            specialCase = true;
        }
        // Checking if element is redundent
        ll lastPos = lastPosition[elements[i]];
        // cout << "lastPos" << lastPos << endl;
        // cout << "lastpos" << lastPos << endl;
        if (lastPos != 0 || (lastPos == 0 && elements[i] == elements[0])){
            hasZeros = true;
            specialCase = true;
            newL = lastPos+1;
        }
        if(specialCase){
            // cout << "special case";
            // Checking if new segment has llersect with old one
            if (newL >= r){
                count++;
                l = newL;
                r = newR;
            }
            else{
                l = max(newL,l);
                r = min(newR, r);
            }
        }
        lastPosition[elements[i]] = i;
        i++;
    }
    if(hasZeros)
        count++;
    cout << count << endl;
    // system("pause");
    return 0;
}