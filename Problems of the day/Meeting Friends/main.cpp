#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> x;
    int input;

    while(cin >> input)
        x.push_back(input);
    sort(x.begin(),x.end());

    int middle;
    int distanceToMiddle = (x[1]-x[0]) + (x[2]-x[1]);

    cout << distanceToMiddle;
}