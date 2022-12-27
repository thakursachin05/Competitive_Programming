// Given an Array of integers A1,A2,....
// N <= 1e5
// 1<=Ai<=1e5

// find number of pairs i,j where Ai is a multiple of Aj and Ai!=Aj



#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+3;

int cnt[MAXN];

int main(){
    int N;
    cin>>N;

    vector<int> A(N);
    for(int i=0;i<N;i++) cin>>A[i];

    for(int i=0;i<N;i++){
        cnt[A[i]]++;
    }

    vector<int> M(MAXN);
    for(int i=1;i<MAXN;i++){
        for(int j = 2*i;j<MAXN; j+= i){
            M[i] += cnt[j];
        }
    }

    // M array has been computed

    long long ans= 0;
    for(int i=0;i<N;i++) ans += M[A[i]];
    cout<<ans<<endl;

    return 0;
}

// TC -- > O(NlogN) 