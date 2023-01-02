#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int solve(int n,int m,vector<int> &v){
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    int ans = 0;

    for(int i=1;i<=n;i++){
        for(int x=1;x<=m;x++){
            if(i==1){
                if(v[i] ==0 || v[i]==x){
                    dp[i][x] = 1;
                }
                else{
                    dp[i][x] = 0;
                }
            }
            else{
                if(v[i] ==0 || v[i]==x){
                    dp[i][x] = ((dp[i-1][x] + dp[i-1][x-1])%mod + dp[i-1][x+1])%mod;
                }
                else{
                    dp[i][x] = 0;
                }
            }
        }
    }

    for(int x=1;x<=m;x++)
        ans = (ans + dp[n][x])%mod;
    return ans; 
    

}

int main(){
    int n,m;
    cin>>n>>m;

    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];
    cout<<solve(n,m,v);
}

