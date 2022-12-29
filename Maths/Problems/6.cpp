// Given P and Q 
// find largest X such that 
// x is a factor of p
// x isn't a multiple of q


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll p,q;
    cin>>p>>q;
    ll ans = 0;
    for(int i=1;i*i<=p;i++){
        if(p%i==0){
            // i and p/i are factors of p
            if(i%q!=0){ // i isn't a multiple of q
                ans = max(ans,i);
            }
            if((p/i)%q!=0){ // p/i isn't a multiple of q
                ans = max(ans,p/i);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}


// TC -- Sqrt(p)


// Another Solution


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


// prime sieve

const int MAXN = 5e4;
bool is_prime[MAXN];
vector<int> primes;

void prime_sieve(){
    is_prime[1] = false;
    for(int i=2;i*i<=MAXN;i++){
        if(is_prime[i]){
            for(int j=i*i;j<=MAXN;j+=i){
                is_prime[j] = false;
            }
        }
    }

    for(int i=2;i<MAXN;i++){
        if(is_prime[i]){
            primes.push_back(i);
        }
    }
}

vector<int> get_prime_factor(ll q){
    vector<int> prime_factors;
    for(int u : primes){
        if(q%u == 0){
            prime_factors.push_back(u);
            while(q%u==0){
                q /= u;
            }
        }
        // iterate till sqrt(q)
        if(u*u > q){
            break;
        }
    }
    if(q>1){
        primes_factors.push_back(q);
    }

    return prime_factors;
}

int main(){
    prime_sieve();
    ll p,q;
    cin>>p>>q;
    if(p%q!=0){
        cout<<p<<endl;
        return 0;
    }
    vector<int> prime_factors = get_prime_factors(q);
    ll ans = 1;

    for(int y : prime_factors){
        ll x = p;
        while(x%q == 0){
            x /= y;
        }
        // x isn't a multiple of q
        // x is factor of p
        ans = max(ans,x);
    }

    cout<<ans<<endl;
    return 0;
}