#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9+7;

int main(){
    ll n,x;
    cin>>n>>x;

    ll arr[n+1];
    for(int i=1;i<=n;i++) cin>>arr[i];

    vector<vector<int>> dp(n+1,vector<int>(x+1,0));

    for(int i=1;i<=n;i++){
        for(int sum = 0;sum<=x;sum++){
            if(sum == 0){
                dp[i][sum] = 1;
            }
            else{
                int op1 = (arr[i] > sum ) ? 0: dp[i][sum-arr[i]];
                int op2 = (i == 1) ? 0 : dp[i-1][sum];
                dp[i][sum] = (op1 + op2)%mod;
            }
        }
    }
    cout<<dp[n][x]<<endl;
}