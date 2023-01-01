#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main(){
    int n,x;
    cin>>n>>x;
    int books[n+1],pages[n+1];
    for(int i=1;i<=n;i++) cin>>books[i];
    for(int i=1;i<=n;i++) cin>>pages[i];

    int dp[n+1][x+1];

    for(int i=0;i<=n;i++){
        for(int cost = 0;cost<=x;cost++){
            if(cost == 0 || i==0){
                dp[i][cost]=0;
            }
            else{
                int op1 = (i==1) ? 0 : dp[i-1][cost];
                int op2 = (cost < books[i]) ? 0 : pages[i] + dp[i-1][cost - books[i]];

                dp[i][cost] = max(op1,op2);
            }
        }
    }

    cout<<dp[n][x]<<endl;

}
