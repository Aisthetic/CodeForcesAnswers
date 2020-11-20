#include <iostream>
#include <array>
#include <vector>
using namespace std;

bool symetric(array<int,4> tile){
    return tile[1] == tile[2];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<array<int,4>> tiles;
        bool anySymetric = false; 
        // reading tiles
        // cout << n << m << endl;
        for(int i = 0; i < n; i ++){
            int a,b,c,d;
            cin >> a >> b >> c  >> d;
            array<int,4> tile{a, b , c , d};
            // cout << a << b << c << d << endl;
            tiles.push_back(tile);
            //Looking if there's any symetric tile
            if(!anySymetric)
                anySymetric = symetric(tile);
        }
        // cout << anySymetric << endl;
        // cout << (m%2==0) << endl;
        cout << ( (anySymetric && m%2==0) ? "YES" : "NO") << endl;  
    }
    return 0;
}

