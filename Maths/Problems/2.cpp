#include<bits/stdc++.h>
using namespace std;

bool is_prime(int X){
    if(X==1) return false;
    int LIM = sqrt(X);
    for(int i=2;i<=LIM;i++){
        if(N%i==0) return false;
    } 
    return true;
}

bool is_almost_prime(int N){
    int LIM = sqrt(N);

    for(int i=2;i<=LIM;i++){
        if(N%i == 0){
            // i is prime
            // N/i is prime
            // i != N/i

            if(is_prime(i) && is_prime(N/i) && i!= N/i) return true;
            else return false;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;

    int ANS = 0;
    for(int i=1;i<=n;i++){
        if(is_almost_prime(i)) ANS++;
    }
    cout<<ANS<<endl;
}

// TC --> N * sqrt(N)