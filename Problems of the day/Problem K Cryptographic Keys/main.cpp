// brute force solution
#include <iostream>  // std::cout
#include <string>
#include <sstream>
using namespace std;
bool isSumOfRest(int pos,int array[4]){
  int sum = 0;
  for(auto i = 0;i < 4;i++){
    if(pos==i) continue;
    sum = sum + array[i];
  }
  return sum == array[pos];
}

bool areSumOfRest(int pos1,int pos2,int array[4]){
  int sum = 0;
  for(auto i = 0;i < 4;i++){
    if(pos1==i || pos2==i) continue;
    sum = sum + array[i];
  }
  return sum == array[pos1]+array[pos2];
}
int main()
{
    int* bags = new int[4];
    for(auto i = 0; i < 4; i ++)
      cin >> bags[i];
    //if one = sum of the others
    for(int i = 0; i < 4; i++){
      if (isSumOfRest(i,bags)){
        cout << "YES";
        exit(0);
      }
    }
    //check combinaisons of 2
    for(int i = 0; i < 4; i++){
      for(int j = i+1; j < 4; j ++){
        if (areSumOfRest(i, j, bags))
        {
          cout << "YES";
          exit(0);
        }
      }
    }
    cout << "NO";
    return 0;
}


