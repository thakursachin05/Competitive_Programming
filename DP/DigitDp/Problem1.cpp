#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define prDouble(x) cout<< fixed << setprecision(10) << x

int dp[101][181][2];


int solve(string &num,int n,int x, bool tight){
    if(x<0) return 0;
    if(n==1){
        if(x >= 0 && x <= 9){
            return 1;
        }
        return 0; 
    }
    if(dp[n][x][tight]!=-1) return dp[n][x][tight];
    int ub = tight ? num[(num.size()-n)] - '0' : 9;
    int answer = 0;
    for(int dig =0;dig<=ub;dig++){
        answer += solve(num,n-1,x-dig,(tight&(dig==ub)));
    }
    return dp[n][x][tight] = answer;
}


int main(){
    memset(dp,-1, sizeof dp);
    string L  = "", R = "15";
    cout<<solve(R,R.length(),5,1);
}