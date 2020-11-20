#include <iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main()
{
    int operations = 0;
    int n=0;
    cin >> n;
    char s[n];
    cin >> s;
    int na=0,nb=0;
    for(int i = 1;i<n+1;i=i+2){
        na = 0;
        nb = 0;
        if(s[i-1]=='a') na++; else nb++;
        if(s[i]=='a') na++; else nb++;
        if(na!=nb){
            //cout << "yes: "<< i <<  << na << " " << nb << endl; 
            operations++;
            if(s[i-1]=='a') s[i-1] = 'b'; else s[i-1] = 'a';
        }
    }
    cout << operations << endl;
    cout << s << endl;
    return 0;
}
