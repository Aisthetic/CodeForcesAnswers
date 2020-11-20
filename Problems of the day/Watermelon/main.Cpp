#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
    // Reading watermelon weight
    int w;
    cin >> w;

    for (int i = 2; i <= w/2 && w-i > 0 ; i=i+2)
    {
        if ((w-i)%2 == 0){
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl; 
    return 0;
}