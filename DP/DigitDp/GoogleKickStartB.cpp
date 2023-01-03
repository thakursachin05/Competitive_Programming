// Boring numbers
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define prDouble(x) cout<< fixed << setprecision(10) << x

ll dp[20][2][2][2];


ll solve(string &R,int n,bool even,bool leadingZero,bool tight){
    if(n==0){
        return 1; 
    }
    if(dp[n][even][leadingZero][tight]!=-1) return dp[n][even][leadingZero][tight];

    if(even){
        vector<int> digits = {0,2,4,6,8};
        int ub = tight ? R[(R.size()-n)] - '0' : 9;
        ll answer = 0;
        
        for(int dig : digits){
            if(dig <= ub)
                answer += solve(R,n-1,0,0,(tight&(dig==ub)));
        }
        return dp[n][even][leadingZero][tight] = answer;
    }
    else{
        vector<int> digits = {1,3,5,7,9};
        int ub = tight ? R[(R.size()-n)] - '0' : 9;
        ll answer = 0;
        if(leadingZero){
            answer += solve(R,n-1,0,1,0);
        }
        for(int dig : digits){
            if(dig <= ub)
                answer += solve(R,n-1,1,0,(tight&(dig==ub)));
        }
        return dp[n][even][leadingZero][tight] = answer;
    }

}


int main(){
    int t;
    cin>>t;
    int k=1;
    while(t--){
        memset(dp,-1, sizeof dp);
        ll L,R;
        cin>>L>>R;
        L--;
        string l  = to_string(L), r = to_string(R);
        ll fr = solve(r,r.length(),0,1,1);
        memset(dp,-1, sizeof dp);
        ll fl = solve(l,l.length(),0,1,1);
        cout<<"CASE #"<<k++<<": ";
        cout<<fr - fl<<endl;
    }
}