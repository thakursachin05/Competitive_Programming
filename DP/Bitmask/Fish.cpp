// CodeForces Div2 E problem Fish

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define prDouble(x) cout<< fixed << setprecision(10) << x
double prob[20][20];
double dp[(1<<19)];
int n;

double pMove(int prev_bitmask,int j){
    int k = __builtin_popcount(prev_bitmask);
    ll den = (k * (k-1))/2;
    double moveProbab = 0;
    for(int fish = 0;fish < n;fish++){
        if(prev_bitmask & (1<<fish)){
            moveProbab += prob[fish+1][j+1];
        }
    }
    return moveProbab/(1.0*den);

}

double solve(int bitMask){
    int alive = __builtin_popcount(bitMask);
    if(alive == n)
        return 1;
    if(dp[bitMask] > -0.9){
        return dp[bitMask];
    }
    
    double answer = 0;
    for(int fish = 0;fish < n;fish++){
        if(!(bitMask & (1<<fish))){
            int prev_bitmask = bitMask^(1<<fish);
            double prev_day = solve(prev_bitmask);
            answer += prev_day * pMove(prev_bitmask,fish);
        }
    }

    return dp[bitMask] = answer;
}

int main(){
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++) cin>>prob[i][j];
    }
    rep(i,0,n){
        prDouble(solve((1<<i)));
        cout<<" ";
    }
        
}