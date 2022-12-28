// Tell if a number has exactly five divisors

#include<bits/stdc++.h>
using namespace std;


const int MAXN = 1e3+5;

set<long long> my_bucket;

bool is_prime[MAXN];

void prime_seive(){
    for(int i=1;i<MAXN;i++){
        is_prime[i] = true;
    }
    is_prime[1] = false;

    for(int i=2;i<MAXN;i++){
        if(is_prime[i]){
            for(int j = i*i;j<MAXN;j+=i){
                is_prime[j] = false;
            }
        }
    }

    for(int i=1;i<MAXN;i++){
        if(is_prime[i]){
            my_bucket.insert(i*i*i*i);
        }
    }
}

bool check_three_divisors(long long N){
    if(my_bucket.find(N)!=my_bucket.end()) return true;
    return false;
}

int main(){
    prime_seive();
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        cout<<check_three_divisors(N)<<endl;
    }
}