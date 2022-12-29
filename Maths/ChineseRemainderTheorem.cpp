#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll power(ll a , ll b, ll prime){
    if(b==0) return 1;

    ll x = power(a,b/2,prime);
    if(b%2==0){
        return (x*x)%prime;
    }
    else {
        ll ans = (x*x)%prime;
        return (ans*a)%prime;
    }
}

ll inverse(ll a, ll prime){
    return power(a,prime-2,prime);
}

int main(){
    ll p1,p2,r1,r2;
    cin>>p1>>p2>>r1>>r2;

    // O(P1*P2)
    // for(int i=0;i<p1*p2;i++){
    //     if(i%p1 == r1 && i%p2==r2){
    //         cout<<i<<endl;
    //     }
    // }

    // Another way
    // O(P2)
    // for(int x = 0;p1*x + r1 < p1*p2;x++){
    //     if((p1*x+r1)%p2 == r2){
    //         cout<<(p1*x+r1)<<endl;
    //     }
    // }

    // r1 * kP1 = X
    ll k = ((r2-r1) * inverse(p1,p2))%p2;
    if(k < p2) k += p2;
    cout<<r1 + k*p1<<endl;
    for(int )
    return 0;
}