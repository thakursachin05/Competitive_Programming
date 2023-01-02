#include<bits/stdc++.h>
using namespace std;

void add(int &subset,int x){
    // because that particular bit is already 0 if xor
    // that bit with 1 then it becomes 1 as well
    
    subset = (subset ^ (1<<x+1));
}

void remove(int &subset,int x){
    subset = (subset ^ (1<<x+1));
}

void display(int subset){
    for(int bit_no=0;bit_no <= 9;bit_no++){
        if(subset & (1<<bit_no)){
            cout<<bit_no+1<<" ";
        }
    }
}


int main(){
    int set = 15;
    remove(set,2);
    add(set,5);
    display(15);
    return 0;
}