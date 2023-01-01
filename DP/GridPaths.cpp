#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    int dp[n+1][n+1];

    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
          
            if(i==n-1 && j==n-1){
                dp[i][j] = 1;
            }
            else{
                int op1 = (j==n-1) ? 0 : dp[i][j+1];
                int op2 = (i==n-1) ? 0 : dp[i+1][j];
                dp[i][j] = (op1 + op2)%mod;

                if(v[i][j]=='*'){
                    dp[i][j] = 0;
                }
            }
        }
    }
    if(v[n-1][n-1] == '*'){
        cout<<0<<endl;
    }
    else 
     cout<<dp[0][0]<<endl;
}