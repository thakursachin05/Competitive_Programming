#include<bits/stdc++.h>
using namespace std;

vector<int> tree[200001];

void solve(int curr, int par,vector<int> &ans){
    int subords = 0;
    
    for(int child : tree[curr]){
        if(child!=par){
            solve(child,curr,ans);
            subords += (1+ans[child]);
        }
    }
    ans[curr] = subords;
}



int main(){
    int n;
    cin>>n;

    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        tree[i].push_back(x);
        tree[x].push_back(i);
    }
    vector<int> ans(n+1);
    solve(1,-1,ans);

    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}