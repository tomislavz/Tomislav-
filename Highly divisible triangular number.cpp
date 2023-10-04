#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int divCount(int n){
    // function for finding no. of divisors

    // sieve method for prime calculation
    bool hash[n + 1];
    memset(hash, true, sizeof(hash));
    for (int p = 2; p * p < n; p++){
        if(hash[p] == true){
            for(int i = p * 2; i < n; i += p){
                hash[i] = false;
            }
        }
    }


    // Traversing through all prime numbers
    int total = 1; 
    for(int p = 2; p <= n; p++){
        if(hash[p]){
            // calculate number of divisor with formula total  
            // div = (p1+1) * (p2+1) *.....* (pn+1)
            // where n = (a1^p1)*(a2^p2).... 
            // *(an^pn) ai being prime divisor
            // for n and pi are their respective power in factorization
            int count = 0;
            if(n % p == 0){
                while(n % p == 0){
                    n = n / p;
                    count++;
                }
                total = total * (count+1);
            }
        }
    }
    return total;
}




int main(){

int n = 1;
//int count = 1;
for (int i = 1; i < 10 ; i ++){

    //Calculate trinagel numbers - Rule: xn = n(n+1)/2
    //https://www.mathsisfun.com/algebra/triangular-numbers.html
    n = i * (i + 1) / 2;

    cout << "Tr_num: " << i << " : " << n << endl;
   // cout <<" Dividors number: "<< divCount(n) << endl;  
    //count = divCount(n);
    //if(count > 9){
       // cout << "Rezultat: " << n << endl;
       // break;
    //}

}

/*bool test = true;
while(test){
    int n = 1;
    int i = 1;
    n = i * (i + 1) / 2;
    
    cout << "Tr_num: " << i << " : " << n << endl;

    if(i > 10){
        test = false;
    }
    i++;
}*/


return 0;
}