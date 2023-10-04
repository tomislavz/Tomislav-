#include <iostream>

using namespace std;

// function
int CollatzSequence(uint64_t num){
    int count = 0;
    while (num > 1)
    {
         
    if (num % 2 == 0){
         num = num / 2;
         count += 1;
    }
    else{
        num = 3 * num + 1;
        count += 1;
    }
    }
   return count;
}


int main(){

int n = 999999;
int longest = 0;
int start_num = 0;

for (int i = n; n > 1; n--){
    
    int result = CollatzSequence(n);

    if(longest < result){
        longest = result;
        start_num = n;
        } 
}

cout << "Najveci: " << longest << endl;
cout << "Start broj: " << start_num;
cout << endl;
cout << CollatzSequence(8400511);


}

