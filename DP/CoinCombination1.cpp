#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
    int n,x;
    cin>>n>>x;

    int arr[n+1];

    for(int i=1;i<=n;i++) cin>>arr[i];

    int dp[x+1];
    dp[0] = 1;

    for(int i=1;i<=x;i++){
        dp[i] = 0;

        for(int j=1;j<=n;j++){
            if(arr[j]<=i)
                dp[i] = (dp[i] + dp[i-arr[j]])%mod;
        }
    }

    cout<<dp[x];
}