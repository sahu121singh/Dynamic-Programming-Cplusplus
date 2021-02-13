#include<bits/stdc++.h>
using namespace std;

// dp or top_down
int fun(int *coins, int n, int sm){
    int dp[n+1][sm+1];
    memset(dp, 0, sizeof(dp));
    
    dp[0][0] = 1;
    
    for(int i = 1; i < n+1; i++){
        for(int j = 0; j < sm+1; j++){
            if(j == 0){
                dp[i][j] = 1;
                continue;
            }
            if(coins[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
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


// recursive
int fun1(int *coins, int n, int sm){
    if(n == 0 && sm != 0){
        return 0;
    }
    if(sm == 0){
        return 1;
    }
    if(coins[n-1] > sm){
        return fun1(coins, n-1, sm);
    }
    else{
        return fun1(coins, n, sm-coins[n-1]) + fun1(coins, n-1, sm);
    }
}

// memoization
int memo[101][101];
int fun2(int *coins, int n, int sm){
    if(n == 0 and sm != 0){
        return 0;
    }
    if(sm == 0){
        return 1;
    }
    if(memo[n][sm] != -1){
        return memo[n][sm];
    }
    if(coins[n-1] > sm){
        memo[n][sm] = fun2(coins, n-1, sm);
    }
    else{
        memo[n][sm] = fun2(coins, n, sm - coins[n-1]) + fun2(coins, n-1, sm);
    }
    return memo[n][sm];
}


int main(){
    int coins[] = {2, 5, 3, 6};
    int n = sizeof(coins)/sizeof(coins[0]);
    int sm = 10;
    cout<<fun(coins, n, sm)<<endl;
    cout<<fun1(coins, n, sm)<<endl;
    
    memset(memo, -1, sizeof(memo));
    cout<<fun2(coins, n, sm)<<endl;
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < sm+1; j++){
            cout<<memo[i][j] << " ";
        }
        cout<<endl;
    }
}