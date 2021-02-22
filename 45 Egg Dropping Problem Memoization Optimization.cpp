#include<bits/stdc++.h>
using namespace std;

int memo[101][101];
int fun(int e, int f){
    if(f == 0 || f == 1){
        return f;
    }
    if(e == 1){
        return f;
    }
    if(memo[e][f] != -1){
        return memo[e][f];
    }
    int mn = INT_MAX;
    for(int k = 1; k <= f; k++){
        int lower, upper;
        if(memo[e-1][k-1] != -1){
            lower = memo[e-1][k-1];
        }
        else{
            lower = fun(e-1, k-1);
        }
        if(memo[e][f-k] != -1){
            upper = memo[e][f-k];
        }
        else{
            upper = fun(e, f-k);
        }
        int temp = 1 + max(lower, upper);
        mn = min(mn, temp);
    }
    memo[e][f] = mn;
    return mn;
}

int main(){
    int f = 36;
    int e = 2;
    memset(memo, -1, sizeof(memo));
    cout<<fun(e, f);
}