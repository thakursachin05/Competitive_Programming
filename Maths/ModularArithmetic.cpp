#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 100000007;

long long power(ll a, ll b){
    ll ans = 1;
    for(int i=1;i<=b;i++){
        ans = (ans*a)%mod;
    }
    return ans;
}


// Modular Exponentiation

long long power(ll a, ll b){
    if(b==0) return 1;
    ll x = power(a,b/2);
    ll ans = 1;
    if(b&1){
        ans = (x*x)%mod;
        ans = (ans * a)%mod;
    }
    else{
        ans = (x * x) % mod;
    }
    return ans;

}

// Calculate Factorial

int values[mod];
ll Factorial(int N){
    ll ans = 1;
    for(int i=1;i<=N;i++){
        ans = (ans*i)%mod;
    }
    return ans;
}


// Fermat's Theoram

// (a/b)%mod = a*b^(mod-2);
int compute(int a, int b){
    int ans = (a * power(b,  mod-2))%mod;
    return ans;
}

int main(){
    cout<<power(2,10000);
    
    int a = 7;
    for(int i=1;i<=mod-1;i++){
        values[i] = (a*i)%mod;
    }
    sort(values,values+mod);

    for(int i=1;i<=mod-1;i++){
        cout<<values[i]<<" ";
    }
    

    int inv = power(a,mod-2);
    cout<<inv<<endl;
    
    return 0;
}


