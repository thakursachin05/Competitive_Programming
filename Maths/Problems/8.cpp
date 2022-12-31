// Combinatorics


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


bool check_bracket_sequence(string s){
    int closing = 0, opening = 0;
    for(auto u : s){
        if(u == '('){
            opening++;
        }
        else if(u == ')'){
            closing++;
        }

        else { 
            return false;
        }

        if(opening < closing) return false;
    }
    if(opening == closing) return true;
    return false;
}


const int MAXN = 1000;

ll ans[MAXN];
ll mod = 1e9+7;




vector<string> generate(int N){
    if(N==0) return {""};
    vector<string> complete_sequence;
    for(int i=0;i<=N-1;i++){
        vector<string> inside_bracket = generate(i);
        vector<string> outside_bracket = generate(N-1-i);

        for(string a : inside_bracket){
            for(string b : outside_bracket){
                string concated = "(" + a + ")" +b;
                complete_sequence.push_back(concated);
            }
        }
    }

    return complete_sequence;

}


int main(){
    ans[0] = 1;
    for(int i=1;i<=MAXN;i++){
        ans[i] = 0;
        for(int j=0;j<=i-1;j++){
            ans[i] =  (ans[i]+ans[j]*ans[i-1-j])%mod;
        } 
    }

    return 0;
}


// Catalan Number have the same formula these code can be represented as catalan Number