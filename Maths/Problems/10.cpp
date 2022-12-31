#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

typedef long long ll;


int main(){
    int N,M;
    cin>>N>>M;

    vector<vector<int>> A(N+1,vector<int> (M+1,0));

    for(int n=1;n<=N;n++){
        for(int m=1;m<=M;m++){
            if(n == 1){
                A[n][m] =  m; // base case
            }
            else{
                for(int i = 1;i<=m-1;i++)
                    A[n][m] += A[n-1][i]; // recurrence
            }
        }
    }
    cout<<A[N][M]<<endl;
    return 0;
}