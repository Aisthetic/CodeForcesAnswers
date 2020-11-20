#include <iostream>
#include <algorithm>
#include <array>

//Calculates the distances
int distance(int a,int b,int c){
    return abs(a-b)+abs(a-c)+abs(b-c);
}

int main(){
    int q;
    std::cin >> q;
    for(int i = 0; i<q;i++){
        int a,b,c;
        std::cin >> a;
        std::cin >> b;
        std::cin >> c;
        if(a==b && b==c)
            std::cout << 0 << std::endl;
        else{
            std::array<int,3> ar = {a,b,c};
            
            std::sort(ar.begin(),ar.end());
            a = ar[0];b=ar[1];c=ar[2];
            if(ar[0] == ar[1] && ar[1] != ar[2]){
                if(abs(b-c)==1)
                    std::cout << distance(a,b,c-1) << std::endl;
                else 
                    std::cout << distance(a+1,b+1,c-1) << std::endl;
                continue;
            }
            else if(ar[0] != ar[1] && ar[1] == ar[2]){
                if(abs(a-b)==1)
                    std::cout << distance(a+1,b,c) << std::endl;
                else 
                    std::cout << distance(a+1,b-1,c-1) << std::endl;
                continue;
            }
            else{
                std::cout << distance(a+1,b,c-1) << std::endl;
                continue;
            }   
        }
    }
    return 0;
} 



//Sorts 3 ints
