// CSES SET PROBLEM
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define prDouble(x) cout<< fixed << setprecision(10) << x

ll dp[20][10][2][2];


ll solve(string &R,int n,int x,bool leading_zeroes,bool tight){
    if(n==0) return 1;
    if(x!=-1 && dp[n][x][leading_zeroes][tight]!=-1) return dp[n][x][leading_zeroes][tight];

    int ub = tight ? (R[R.length()-n]-'0') : 9;
    
    ll answer = 0;

    for(int dig = 0;dig<=ub;dig++){
       if(dig == x && !leading_zeroes){
        continue;
       }
       answer += solve(R,n-1,dig,leading_zeroes & (dig==0) , tight & (dig==ub));
    }
    return dp[n][x][leading_zeroes][tight] = answer;
}


int main(){
    int t = 1;
    // int k=1;
    while(t--){
        ll L,R;
        cin>>L>>R;
        L--;
        string l  = to_string(L), r = to_string(R);
        memset(dp,-1, sizeof dp);
        ll fr = solve(r,r.length(),-1,1,1);
        memset(dp,-1, sizeof dp);
        ll fl = solve(l,l.length(),-1,1,1);
        // cout<<"CASE #"<<k++<<": ";
        cout<<fr - fl<<endl;
    }
}