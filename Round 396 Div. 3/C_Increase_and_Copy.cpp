#include <iostream>
#include <array>
#include <vector>
#include <math.h>

using namespace std;

bool isInt(float f)
{
    return ceilf(f) == f;
}
void print(vector<int> vec)
{
    for (auto &n : vec)
        cout << n << " ";
    cout << endl;
}
void logVar(string msg, int var)
{
    cout << msg << " " << var << endl;
}
void logVar(string msg, float var)
{
    cout << msg << " " << var << endl;
}
int largestDivider(int n)
{
    int i = n;
    while (--i && i > n / 2)
    {
        if (n % i == 0)
            return i;
    }
    return 1;
}
array<int, 2> middleDividers(int n)
{
    float sqrtn = sqrt(n);
    logVar("sqrt", sqrtn);
    if (isInt(sqrtn))
        return array<int, 2>{(int)sqrtn, (int)sqrtn};
    for (int i = sqrtn; i < n; i++)
    {
        if (n % i == 0)
            return array<int, 2>{i, n / i};
    }
    return array<int, 2>{1, n};
}
int sum(vector<int> vec)
{
    int sum_of_elems = 0;
    for (auto &n : vec)
        sum_of_elems += n;
    // logVar("sumofelems",sum_of_elems);
    return sum_of_elems;
}
int main1()
{
    int t;
    cin >> t;
    vector<int> vec;
    int movesCount = 0;
    while (t--)
    {
        int n;
        cin >> n;
        if(n==1){
             cout << 0 << endl;
             continue;
        }
        float sqrtn = sqrt(n);
        int sqrtnint = sqrtn;
        // logVar("sqrtint",sqrtnint);
        float decimal = sqrtn - (float)sqrtnint;
        movesCount = sqrtnint*2 - 2;
        int difference = n - pow(sqrtnint,2);

        if(difference > 0){
            if (isInt((float)difference/sqrtnint))
                movesCount +=  difference / sqrtnint;
            else
                movesCount +=  difference / sqrtnint + 1;
        }
        cout << movesCount << endl;
    }
    // system("pause");
    return 0;
}

int main(){
    for (size_t i = 0; i < 100; i++)
    {
        cout << i << endl;
        
        i = 90;
    }
    system("pause");
}
