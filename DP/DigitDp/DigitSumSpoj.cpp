// Boring numbers
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define prDouble(x) cout<< fixed << setprecision(10) << x

ll dp[18][2];

ll cnt(string& R,int n,bool tight){
    if(tight == 0){
        return (pow(10,n)+0.1);
    }
    if(n==0){
        return 1;
    }
    ll numbers = 0;
    int ub = tight ? (R[R.length()-n]-'0') : 9;
    for(int dig = 0;dig<=ub;dig++){
        numbers += cnt(R,n-1,tight & (dig==ub));
    }
    return numbers;
}


ll solve(string &R,int n,bool tight){
    if(n==0) return 0;
    if(dp[n][tight]!=-1) return dp[n][tight];

    int ub = tight ? (R[R.length()-n]-'0') : 9;
    ll total = 0;

    for(int dig = 0;dig <=ub;dig++){
        total += (dig*cnt(R,n-1,tight & (dig ==ub)));
        total += solve(R,n-1,tight & (dig ==ub));
    }
    return dp[n][tight] = total;
}


int main(){
    int t;
    cin>>t;
    int k=1;
    while(t--){
        ll L,R;
        cin>>L>>R;
        L--;
        string l  = to_string(L), r = to_string(R);
        memset(dp,-1, sizeof dp);
        ll fr = solve(r,r.length(),1);
        memset(dp,-1, sizeof dp);
        ll fl = solve(l,l.length(),1);
        cout<<"CASE #"<<k++<<": ";
        cout<<fr - fl<<endl;
    }
}