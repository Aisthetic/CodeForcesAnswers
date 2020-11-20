#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
#define ll long long

struct suite
{
    bool type; // true for ns, fasle for as
    int count;
    char last, first;
};
void printS(list<suite> s);

int main()
{
    ll t;
    cin >> t;
    int i = 1;
    while (t--)
    {
        ll n;
        cin >> n;
        // if (i == 55)
        // {
        //     for (size_t i = 0; i < n; i++)
        //     {
        //         char c;
        //         cin >> c;
        //         cout << c;
        //     }
        //     cout << endl;
        //     // i++;
        //     continue;
        // }
        char current = '\0', last = '\0';
        if (n <= 2)
        {
            if(n==2) cin >> current;
            cin >> current;
            cout << "1" << endl;
            continue;
        }
        int end = 0, begin = 0, lastEnd = -1;
        bool seq = false;
        char *chars = new char[n];
        int *sequences = new int[n]; // 1 for ns, 0 for as
        int level = 0;               // used to differentiate betwen consecutive ns
        list<suite> suites;
        //Building suites
        suite ns, as;
        as.count = 0;
        ns.count = 0;
        int secondLevel = 1;
        // building suites is décalé de -1 % à building sequences
        for (ll i = 0; i < n + 1; i++)
        {
            if( i == n)
                goto buildsuites;
            last = current;
            cin >> current;
            while (current == '\0')
                cin >> current;
            chars[i] = current;
            if ((last != '0' && last != '1')) // first character
                goto buildsuites;
            // Begin of sequence cases
            if (last == current)
            {
                if (!seq)
                {
                    seq = true;
                    begin = i - 1;
                    level++;
                }
                sequences[i] = level;
                sequences[i - 1] = level;
            }
            //End of sequence case
            if (last != current)
            {
                if (seq)
                {
                    seq = false;
                    end = i - 1;
                    // cout << "2[" << begin << ":" << end << "]" << endl;
                    sequences[i] = 0; // i is not part of the sequence
                }
                else
                {
                    sequences[i] = 0;
                    sequences[i - 1] = 0;
                }
            }
            else if (i == n - 1)
            {
                seq = false;
                end = i;
                // cout << "1[" << begin << ":" << end << "]" << endl;
            }
            //Building suites
            buildsuites:
            ll j = i -1;
            if(j<0) continue;
            // cout << "seqs" <<  j << ": " << sequences[j] << endl;
            if (sequences[j] != secondLevel)
            {
                if (ns.count != 0)
                {
                    suites.push_back(ns);
                    ns.count = 0;
                    as.first = chars[j]; // we don't know if next is going to be
                    ns.first = chars[j]; // as or ns so we do this as it's same
                    secondLevel++;
                }
            }
            if (sequences[j] == secondLevel)
            {
                // in case we were reading an as, we add it and delete its data
                // and we start reading the ns
                if (as.count != 0)
                {
                    suites.push_back(as);
                    as.count = 0;
                    ns.first = chars[j];
                }
                ns.count++;
                ns.last = chars[j];
                ns.type = true;
            }
            else if (sequences[j] == 0)
            {
                as.count++;
                as.last = chars[j];
                as.type = false;
            }
            if (j == n - 1)
            {
                if (ns.count != 0)
                {
                    suites.push_back(ns);
                    ns.count = 0;
                    as.first = chars[j];
                }
                if (as.count != 0)
                {
                    suites.push_back(as);
                    as.count = 0;
                    ns.first = chars[j];
                }
            }
        }

        // printS(suites);
        // return 0;
        //Data treatment
        ll movescnt = 0;
        for (auto s = suites.begin(); s != suites.end(); ++s)
        {
            // cout << movescnt << endl;
            // cout << i,printS(suites);
            // in case the seq is consumed we skip it
            if (s->count <= 0)
                continue;
            // s is not a seq, we merge it with the next
            if (s->count == 1)
            {
                auto nextS = next(s, 1);
                if (nextS == suites.end())
                { // last element
                    movescnt++;
                    break;
                }
                if (s->last == nextS->first)
                {
                    if (nextS->type == true) // we merge it with the ns
                    // then treatment comes on the next loop
                    {
                        nextS->first = s->last;
                        nextS->count++;
                    }
                    else
                    {
                        // we create an ns
                        s->count++;
                        s->type = true;
                        s--;
                    }
                }
                else
                {
                    if (nextS->type == false) // we merge it with the as
                    // then treatment comes on the next loop
                    {
                        nextS->first = s->last;
                        nextS->count++;
                    }
                    else
                    {
                        if (nextS->count == 1) // we create an as of 2 elts
                        {
                            s->count--;
                            nextS->first = s->last;
                            nextS->count++;
                            nextS->type = false;
                        }
                        // we consume one from the nextS
                        else
                        {
                            nextS->count--;
                            s->count--;
                            movescnt++;
                        }
                    }
                }
                continue;
            }
            // ns are consumed
            if (s->type == true)
            {
                s->count = 0;
                movescnt++;
                continue;
            }
            else
            {
                auto nextS = next(s, 1);
                // if this is not the last seq
                if (nextS != suites.end())
                {
                    // good, consume each other then continue
                    if (nextS->count > s->count)
                    {
                        movescnt += s->count;
                        nextS->count -= s->count;
                        s->count = 0;
                        continue;
                    }
                    else if (nextS->count == s->count)
                    {
                        movescnt += s->count - 1;
                        nextS->count -= s->count - 1;
                        s->count = 1;
                        nextS->count = 1;
                        s--;
                        continue;
                    }
                    else
                    { //in this case we've got to deal with what's left of as after
                        // consuming ns till it has just one element
                        // then we merge it with the current as
                        movescnt += nextS->count - 1;
                        s->count -= nextS->count - 1;
                        // adding the only left element of nextS to the as s
                        s->count += 1;
                        s->last = nextS->last; //last or first, same for ns
                        suites.erase(nextS);
                        s--;
                        continue;
                    }
                }
                // else we consume what's left of as
                else
                    movescnt += (s->count + 1) / 2;
            }
        }
        cout << movescnt << endl;
        i++;
    }
    return 0;
}

void printS(list<suite> suites)
{
    cout << "--------------------------" << endl;
    for (auto s = suites.begin(); s != suites.end(); ++s)
    {
        cout << s->count << "/" << s->type << endl;
    }
    cout << "--------------------------" << endl;
}
