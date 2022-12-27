#include<bits/stdc++.h>
using namespace std;

bool is_prime(int X){
    if(X==1) return false;
    int LIM = sqrt(X);
    for(int i=2;i<=LIM;i++){
        if(N%i==0) return false;
    } 
    return true;
}

bool is_almost_prime(int N){
    int LIM = sqrt(N);

    for(int i=2;i<=LIM;i++){
        if(N%i == 0){
            // i is prime
            // N/i is prime
            // i != N/i

            if(is_prime(i) && is_prime(N/i) && i!= N/i) return true;
            else return false;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;

    int ANS = 0;
    for(int i=1;i<=n;i++){
        if(is_almost_prime(i)) ANS++;
    }
    cout<<ANS<<endl;
}

// TC --> N * sqrt(N)





// More optimize using sieve



const int MAXN = 1e5+3;
bool prime[MAXN];
void prime_seive(){
    for(int i=1;i<=MAXN;i++)
        prime[i] = true;
    prime[1] = false;
    for(int i=2;i<=MAX;i++){
        if(prime[i]){
            for(int j = i*i;j<=MAXN;j+=i){
                prime[j] = false;
            }
        }
    }
}

bool almostPrime[MAXN];

int compute_answer(int N){
    for(int i=2;i<=N;i++){
        if(prime[i]){
            for(int j=i;j<=N;j+=i){
                // j = i*something
                // something should be prime
                // and something should not be equal to i
                if(prime[j/i] && j/i != i){
                    almostPrime[j] = true;
                }   
            }
        }
    }

    int ANS = 0;

    for(int i=1;i<=N;i++){
        if(almostPrime[i]){
            ANS++;
        }
    }

    return ANS;
}

// prime sieve --> NloglogN
// TC  -> O(NlogN)





// Another Approach


const int MAXN = 1e5+3;
bool prime[MAXN];
int spf[MAXN];

void prime_seive_and_spf(){
    for(int i=1;i<=MAXN;i++)
        prime[i] = true;
    prime[1] = false;
    for(int i=2;i<=MAX;i++){
        if(prime[i]){
            for(int j = i*i;j<=MAXN;j+=i){
                prime[j] = false;
            }
        }
    }

    for(int i=2;i<MAXN;i++){
        if(prime[i]){
            for(int j=i;j<MAXN;j+=i){
                if(spf[j] == 0) spf[j] = i;
            }
        }
    }
}

int compute_answer(int N){
    int ans = 0;
    for(int i = 1;i<=N;i++){
        int A = spf[i];
        int B = spf[N/A];
        if(A!=B && prime[A] && prime[B] && A*B==N){
            ans++;
        }
    }
    return ans;
}