// How to check a number is prime or not

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

// Function to check prime or not
// O(N) --> TC

bool isPrime(int N){
    if(N == 1){
        return false;
    }
    for(int i=2;i<=N-1;i++){
        if(N%i==0) return false;
    }
    return true;
}


// Optimized function for checking the number is prime
// TC --> O(sqrt(N))

bool isPrime(int N){
    if(N == 1){
        return false;
    }
    int L = sqrt(N);
    for(int i=2;i<=L;i++){
        if(N%i==0) return false;
    }
    return true;
}

// Sieve

bool prime[MAXN];

// TC --> O(N * sqrt(N))

void till_primes(){
    for(int i=1;i<MAX;i++){
        prime[i] = isPrime(i);
    }
}


// More optimized 
// TC --> O(N logN)

void fill_primes(){
    for(int i=1;i<MAXN;i++){
      prime[i] = true;  
    }
    prime[1] = false;

    for(int i=2;i<MAXN;i++){
        if(prime[i]){
            for(int j= i*i;j<MAXN;j+=i){
                prime[j] = false;
            }
        }
        if(i*i > MAXN){
            break;
        }
    }
}


int main(){


    return 0;
}