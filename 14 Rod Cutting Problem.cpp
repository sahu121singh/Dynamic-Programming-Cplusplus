#include<bits/stdc++.h>
using namespace std;

// DP
int fun(int *price, int *len, int N, int l){
    int dp[N+1][l+1];
    memset(dp, 0, sizeof(dp));
    
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < l+1; j++){
            
            if(len[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(price[i-1] + dp[i][j-len[i-1]], dp[i-1][j]);
            }
        }
    }
    for(int i = 0; i < N+1; i++){
        for(int j = 0; j < l+1; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[N][l];
}

// Recursive
int fun1(int *price, int *len, int n, int l){
    if(n==0 || l==0){
        return 0;
    }
    if(len[n-1] > l){
        return fun1(price, len, n-1, l);
    }
    else{
        return max(price[n-1] + fun1(price, len, n, l-len[n-1]), fun1(price, len, n-1, l));
    }
}

// memoization
int memo[101][101];
int fun2(int *price, int *len, int n, int l){
    if(n==0 || l==0){
        return 0;
    }
    if(memo[n][l] != -1){
        return memo[n][l];
    }
    if(len[n-1] <= l){
        memo[n][l] = max(price[n-1] + fun2(price, len, n, l-len[n-1]), fun2(price, len, n-1, l));
    }
    if(len[n-1] > l){
        memo[n][l] = fun2(price, len, n-1, l);
    }
    return memo[n][l];
    
}

int main(){
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int N = sizeof(price)/sizeof(price[0]);
    
    int rod_length = 8;
    int len[N];
    for(int i = 0; i < N; i++){
        len[i] = i+1;
    }
    cout<<fun(price, len, N, rod_length)<<endl;
    cout<<fun1(price, len, N, rod_length)<<endl;
    
    memset(memo, -1, sizeof(memo));
    cout<<fun2(price, len, N, rod_length)<<endl;
    for(int i = 0; i < N+1; i++){
        for(int j = 0; j < rod_length+1; j++){
            cout<<memo[i][j]<<" ";
        }
        cout<<endl;
    }
}