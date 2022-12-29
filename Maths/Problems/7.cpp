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

int main(){

    ll a,b,p;
    cin>>a>>b>>p;
    for(int x=0;x<=p-2;x++){
        if(power(a,x,p) == b){
            cout<<x<<endl;
            return 0;
        }
    }
    cout<<"NOT POSSIBLE"<<endl;
    /// TC =--- O(PlogP)
    
    // Another optimization
    // TC ---> O(P)
    ll current = 1;
    for(int x=0;x<=p-2;x++){
        if(current == b){
            cout<<x<<endl;
            return 0;
        }
        current = (current*a)%p;
    }

    //Must optimization version 
    // Algo used is known as baby step and grand step
    // application of fermet theorem and we are able to manage X into another form and thus optimized it

    unordered_map<ll,ll> r_value;
    ll z = floor(sqrt(p));
    for(int r = 0;r<=p/z;r++){
        r_value[power(a,r*z,p)] = r;
    }
    ll X = -1;
    for(int q = 0; q<z;q++){
        ll e = power(inverse(a,p),q);
        ll lhs = (b*e)%p;
        if(r_value.find(lhs)!=r_value.end()){
            X = r_value[lhs]*z + q;
            break;
        }
    }

    if(X ==-1){
        cout<<"NOT FOUND"<<endl;
    }
    else 
        cout<<X<<endl;


    // O(Sqrt(p)logP)


    // Another optimization in log P
    
    unordered_map<ll,ll> r_value;
    ll z = floor(sqrt(p));

    ll d = power(a,z,p);
    ll current = 1;
    for(int r = 0;r<=p/z;r++){
        r_value[current] = r;
        current = current*d;
    }
    ll X = -1;
    ll D = inverse(a,p);
    current = 1;
    for(int q = 0; q<z;q++){
        ll e = current;
        ll lhs = (b*e)%p;
        if(r_value.find(lhs)!=r_value.end()){
            X = r_value[lhs]*z + q;
            break;
        }
        current = current * D;
    }

    if(X ==-1){
        cout<<"NOT FOUND"<<endl;
    }
    else 
        cout<<X<<endl;



    // TC --> O(sqrt(p))
    return 0;
}