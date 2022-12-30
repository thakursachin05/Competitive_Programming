#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1e6;

const ll mod = 1e9+7;
ll fac[MAXN];

// a*b % mod
ll power(ll a,ll b){
    if(b==0) return 1;
    ll ans = power(a,b/2);

    if(b%2==0){
        ll X = power(a,b/2);
        return (X*X)%mod;
    }
    else{
        ll X = power(a,b/2);
        ll ans = (X*X)%mod;
        return (ans*a)%mod;
    }
}

ll inverse(ll a){
    return power(a, mod-2);
}

void compute_factorials(){
    fac[0] = 1;
    invfac[0] = 1;
    for(int i=1;i<MAXN;i++){
        fac[i] = (fac[i-1]*i)%mod;
        invfac[i] = inverse(fac[i]);
    }
}


ll nCr(ll N, ll R){
    if(N == 0 || R < 0 || R > N){
        return 0;
    }

    ll num = fac[N];
    ll den = (invfac[R]*invfac[N-R])%mod;
    return (num*den)%mod;
}

ll ans[MAXN];

void compute_product_OddNumbers(){
    ans[1] = 1;
    for(int i=2;i<MAXN;i++){
        ans[i] = (ans[i-1] * (2*i - 1))%mod;
    }
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<ans[n]<<endl;
    }



    // Finding Diagonals
    ll n;
    cin>>n;
    ll  diagonals = (n*(n-3))/2;
    cout<<diagonals<<endl;
    return 0;
}