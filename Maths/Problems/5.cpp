// Count number of triangles whose side is A, which is not hypotenuse
// and triangle is right angled triangle

#include<bits/stdc++.h>
using namespace std;

int count(int N){
    int ans = 0;
    long long lim = (long long ) N*N;
    for(int x=1;x*x<=lim;x++){
        if(N%x==0){
            // x * y = N
            long long y = lim/x;
            if(x < y && (x%2 == y%2)){
                long long C = (x+y)/2;
                long long B = (y-x)/2;
               // N * N + B*B = C*C
                ans++;
            }
        }
    }
    return ans;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        cout<<count(N)<<endl;
    }
}