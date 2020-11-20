#include <iostream>
#include <array>
#include <math.h>
using namespace std;
struct player
{
    int R;
    int S;
    int P;
};

int main()
{
    int n;
    cin >> n;
    player Alice, Bob, Alice1, Bob1;
    cin >> Alice.R;
    cin >> Alice.S;
    cin >> Alice.P;
    cin >> Bob.R;
    cin >> Bob.S;
    cin >> Bob.P;
    Alice1 = Alice;
    Bob1 = Bob;
    int numberOfWins = 0, tmp;
    //MAX WINS
    //Rock
    if (Alice.R != 0 && Bob.S != 0)
    {
        tmp = Alice.R > Bob.S ? Bob.S : Alice.R;
        numberOfWins += tmp;
        Alice.R -= tmp;
        Bob.S -= tmp;
    }
    //Scissors
    if (Alice.S != 0 && Bob.P != 0)
    {
        tmp = Alice.S > Bob.P ? Bob.P : Alice.S;
        numberOfWins += tmp;
        Alice.S -= tmp;
        Bob.P -= tmp;
    }
    //Paper
    if (Alice.P != 0 && Bob.R != 0)
    {
        tmp = Alice.P > Bob.R ? Bob.R : Alice.P;
        numberOfWins += tmp;
        Alice.P -= tmp;
        Bob.R -= tmp;
    }
    // MIN NB OF WINS = n - draw - max LOSSES
    // NB OF LOSSES
    int maxLosses = 0;
    if (Alice1.R != 0 && Bob1.P != 0)
    {
        tmp = Alice1.R > Bob1.P ? Bob1.P : Alice1.R;
        maxLosses += tmp;
        Alice1.R -= tmp;
        Bob.P -= tmp;
    }
    //Scissors
    if (Alice1.S != 0 && Bob1.R != 0)
    {
        tmp = Alice1.S > Bob1.R ? Bob1.R : Alice1.S;
        maxLosses += tmp;
        Alice1.S -= tmp;
        Bob1.R -= tmp;
    }
    //Paper
    if (Alice1.P != 0 && Bob1.S != 0)
    {
        tmp = Alice1.P > Bob1.S ? Bob1.S : Alice1.P;
        maxLosses += tmp;
        Alice1.P -= tmp;
        Bob1.S -= tmp;  
    }
    //Nb of draws
    int nbOfDraws = 0;
    tmp = Alice1.S > Bob1.S ? Bob1.S : Alice1.S;
    nbOfDraws += tmp;
    Alice1.S -= tmp;
    Bob1.S -= tmp;
    tmp = Alice1.R > Bob1.R ? Bob1.R : Alice1.R;
    nbOfDraws += tmp;
    Alice1.R -= tmp;
    Bob1.R -= tmp;
    tmp = Alice1.P > Bob1.P ? Bob1.P : Alice1.P;
    nbOfDraws += tmp;
    Alice1.P -= tmp;
    Bob1.P -= tmp;
    int nbOfMinWins = n - (maxLosses + nbOfDraws);
    cout << nbOfMinWins << " " << numberOfWins << endl;
}
