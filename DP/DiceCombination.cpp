#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9+7;

int dp[1000100];

int main(){
    ll n;
    cin>>n;
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for(int x = 1; x<=6;x++){

            if(x > i){
                break;
            }
            dp[i] = (dp[i] + dp[i-x])%mod;
        }
    }
    cout<<dp[n]<<endl;
}