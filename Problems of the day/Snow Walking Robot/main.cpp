#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q = 0;
    cin >> q;
    for(int i =0;i<q;i++){
        string s;
        cin>>s;
        int U=0,D=0,R=0,L=0;
        for(char c:s){
            if(c=='U') U++;
            else if (c=='D') D++;
            else if (c=='R') R++;
            else if (c=='L') L++;
        }
        L=R=min(L,R);
        D=U=min(D,U);
        cout << D+L+R+U << endl;
        cout << string(D,'D') << string(R,'R') << string(U,'U') << string (L,'L') << endl;
    }
    return 1;
}