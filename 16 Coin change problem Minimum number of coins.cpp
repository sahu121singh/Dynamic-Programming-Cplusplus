#include<bits/stdc++.h>
using namespace std;

int I = INT_MAX-1;

// dp or top_down
int fun(int *coins, int n, int sm){
    int dp[n+1][sm+1];
    for(int j = 0; j < sm+1; j++){
        dp[0][j] = I;
    }
    for(int i = 1; i < n+1; i++){
        dp[i][0] = 0;
    }
    
    for(int j = 1; j < sm+1; j++){
        if(j%coins[0] == 0){
            dp[1][j] = j/coins[0];
        }
        else{
            dp[1][j] = I;
        }
    }
    
    for(int i = 2; i < n+1; i++){
        for(int j = 1; j < sm+1; j++){
            if(coins[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
            }
        }
    }
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < sm+1; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][sm];
}

/*
int fun1(int *coins, int n, int sm){
    if(n  == 0 && sm == 0){
        return I;
    }
    if(n == 0 && sm != 0){
        return I;
    }
    if(sm == 0){
        return 0;
    }
    if(sm%coins[0] != 0){
        return I;
    }
    if(sm%coins[0] == 0){
        return sm/coins[0];
    }
    if(coins[n-1] > sm){
        return fun1(coins, n-1, sm);
    }
    else{
        return min(1 + fun1(coins, n-1, sm-coins[n-1]), fun1(coins, n-1, sm));
    }
}

*/

int main(){
    int coins[] = {9, 6, 5, 1};                           // (1.) 1, 2, 3      (2.)  25, 10, 5
    int n = sizeof(coins)/sizeof(coins[0]);
    int sm = 11;                                          // (1.) 5            (2.)   30
    cout<<fun(coins, n, sm);                              // (1.)   2          (2.)    2
}