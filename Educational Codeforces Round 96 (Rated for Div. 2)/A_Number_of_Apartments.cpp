#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a, b, c, tmp;
        bool found = false;
        a = b = c = 0;
        for (c = 0; n - 7 * c >= 0; c++)
        {
            for (b = 0; n - 5 * b >= 0; b++)
            {
                tmp = n - 7 * c - 5 * b;
                if (tmp % 3 == 0)
                {
                    a = tmp / 3;
                    cout << a << " " << b << " " << c << endl;
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }
        if (!found){
            cout << "-1" << endl;
        }
    }

    return 0;
}