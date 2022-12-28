// A number is given upto 1e12 tell if it has 3 divisors or not

#include<bits/stdc++.h>
using namespace std;


long long square_root(long long N){
    for(long long i = 1;i*i<=N;i++){
        if(i*i == N){
            return i;
        }
    }
    return -1;
}

bool is_prime(long long N){
    if(N==1) return false;
    for(int i=2;i*i<=N;i++){
        if(N%i == 0){
            return false;
        }
    }
    return true;
}

bool check_three_divisors(long long N){
    long long A = square_root(N);
    if(A==-1) return false;

    if(is_prime(A)) return true;
    return false;
}


int main(){
    long long N;
    cin>>N;
    cout<<check_three_divisors(N)<<endl;
    return 0;
}

// TC -- O(Sqrt(N) + Sqrt(Sqrt(N)));


// Another Approach

#include<bits/stdc++.h>
using namespace std;


const int MAXN = 1e6+5;

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
            my_bucket.insert(i*i);
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

// TC --> NloglogN

