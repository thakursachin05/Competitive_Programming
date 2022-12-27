// Divisors

#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

// TC ---> O(N/2)

void print_factors(int N){
    for(int i=1;i<=N/2;i++){
        if(N%i==0) cout<<i<<endl;
    }
    cout<<N<<endl;
}

// Optimized version
// TC ---> O(sqrt(N))

void print_factors(int N){
    int L = sqrt(N);
    for(int i=1;i<=L;i++){
        if(N%i==0) {
            cout<<i<<endl;
            if(i != N/i)
                cout<<N/i<<endl;
        }
    }
}

// countFactors

int count_factors(int N){
    int L = sqrt(N);
    int factor_count = 0;
    for(int i=1;i<=L;i++){
        if(N%i==0) {
            factor_count++;      
            if(i != N/i){
                factor_count++;
            }
        }
    }
    return factor_count;
}


int cnt[MAXN];

void fill_count_of_factors(int N){
    for(int i=1;i<=N;i++){
        cnt[i] = count_factors(i);
    }
}


// if we want to do More quickly
// TC --> NlogN 

void fill_count_of_factors(int N){
    for(int i=1;i<=N;i++){
        for(int j = i;j<=N;j+=i) cnt[j]++;
    }
}


int main(){


    return 0;
}