#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
#define ll long long

void print(list<char>);
int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll n, cnt = 0;
        cin >> n;
        list<char> chars;
        char current = '\0', last = '\0';
        if (n <= 2)
        {
            if (n == 2)
                cin >> current;
            cin >> current;
            cout << "1" << endl;
            continue;
        }
        for (ll i = 0; i < n; i++)
        {
            last = current;
            cin >> current;
            while (current == '\0')
                cin >> current;
            chars.push_back(current);
        }
        bool isDeletingNs = false;
        list<char>::iterator nextc;
        auto cend = chars.end();
        // if we invalidated the itterator, we put the next of the last valid one
        // else we act normal, i.e s++
        for (auto s = chars.begin(); s != chars.end(); (s == nextc) ? (s = s) : s++)
        {
            // print(chars);
            nextc = next(s, 1);
            auto lastc = prev(s, 1);
            char vs = *s, snextc = *nextc;

            if (nextc == chars.end())
            {
                // 1 char left
                if (s == chars.begin())
                {
                    cnt++;
                    break;
                }
                // at this point lastc must be valid
                if (isDeletingNs)
                {
                    // an ns is left
                    if (*lastc == *s)
                    {
                        isDeletingNs = false;
                        cnt++;
                        break;
                    }
                    else
                    { // an ns + 1 char is left
                        cnt += 2;
                        isDeletingNs = false;
                        break;
                    }
                }
                else
                {
                    // as is left + 1 element
                    if (*lastc == *s)
                    {
                        cnt += (chars.size() + 1)/2;
                        break;
                    }
                    // as is left (same treatment)
                    else{
                        cnt += (chars.size() + 1)/2;
                        break;
                    }
                }
                continue;
            }
            // handling ns at the begging of the string
            if (s == chars.begin() && *s == *nextc)
            {
                isDeletingNs = true;
                chars.pop_front();
                // we delete s from the list, it is invalid now
                s = nextc; // this is a way of showing that the iterator is not valid
                vs = *s;
                continue;
            }
            // handling as at the beggining of the string
            if (s == chars.begin() && *s != *nextc)
            {
                // if we were deleting an ns, we delete it last
                // element, then we add 1 to the counter
                if (isDeletingNs)
                {
                    // we delete s from the list, it is invalid now
                    s = nextc; // this is a way of showing that the iterator is not valid
                    chars.pop_front();
                    cnt++;
                }
                isDeletingNs = false;
                continue;
            }
            // checking if (i-1) != (i+1) then consuming i
            // if it is the case
            if (*lastc != *nextc)
            {
                chars.erase(s);
                // we need to do a s--, but s is invalid so we
                // affect last (if it is valid) to s
                if (lastc == chars.begin())
                    s = nextc;
                else
                    s = lastc;
                chars.pop_front();
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
void print(list<char> chars)
{
    for (auto s = chars.begin(); s != chars.end(); ++s)
    {
        cout << *s;
    }
    cout << endl;
}