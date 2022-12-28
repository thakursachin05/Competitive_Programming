#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 100000007;

ll power(ll a, ll b){
    if(b==0) return 1;
    ll ans = power(a,b/2);
    ans = (ans*ans)%mod;
    if(b&1){
        ans = (ans*a)%mod;
    }
    return ans;
}


ll inverse(ll a){
    return power(a,mod-2);
}

ll fac(ll N){
    ll ans = 1
    for(int i=1;i<=N;i++){
        ans = (ans*i)%mod;
    }
    return ans;
}

const int MAXN = 1e5+5;

ll factorial[MAXN];
ll inverse_factorial[MAXN];

ll precompute_factorial(){
    factorial[0] = 1;
    for(int i=1;i<MAXN;i++){
        factorial[i] = i*factorial[i-1];
    }
    // for(int i=1;i<MAXN;i++){
    //     inverse_factorial[i] = inverse(factorial[i]);
    // }
    inverse_factorial[MAXN-1] = inverse(factorial[MAXN-1]);
    for(int i=MAXN-1;i>=1;i--){
        inverse_factorial[i-1] = (i*inverse_factorial[i])%mod;
    }
 
}


int main(){
    precompute_factorial();
    int t;
    cin>>t;
    while(t--){
        int n,r;
        cin>>n>>r;

        // N choose R
        // N! / (R! * (N-R)!)
        ll nfact = factorial[n];
        ll rfact = inverse_factorial[r];
        ll nrfact = inverse_factorial[n-r];
       
        ll ans = (nrfact*nfact)%mod;
        ans = (ans*rfact)%mod;
        return ans;
    }
    
    return 0;
}



// Trialing zeroes code


in power_p(int n,int p){
    int G = p;
    int ans = 0;
    while(G<=n){
        ans += n/G;
        G *= p;
    
    }
    return ans;
}

int trailing_zeros(int N){
    return power_p(N,5);
}




// Another variaition to find the trailing zeroes in ncr

int trailing_zeros(int N,int R){
    int x = power_p(N,2)-power_p(R,2)-power_p(N-R,2);
    int y = power_p(N,5)-power_p(R,5)-power_p(N-R,5);
    return min(x,y);
}