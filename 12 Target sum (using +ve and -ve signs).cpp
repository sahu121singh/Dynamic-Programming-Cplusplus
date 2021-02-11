#include<bits/stdc++.h>
using namespace std;

// Top-Down
int fun(int *arr, int n, int sm){
    int dp[n+1][sm+1];
    memset(dp, 0, sizeof(dp));
    
    dp[0][0] = 1;
    
    for(int i = 1; i < n+1; i++){
        for(int j = 0; j < sm+1; j++){
            if(j==0){
                dp[i][j] = 1;
            }
            else if(arr[i-1] > sm){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j - arr[i-1]] + dp[i-1][j];
            }
        }
    }
    return dp[n][sm];
}

// Recursive
int fun1(int arr[], int n, int sm){
    if(sm == 0 and n >=0){
        return 1;
    }
    if(n==0 and sm != 0){
        return 0;
    }
    if(arr[n-1] > sm){
        return fun1(arr, n-1, sm);
    }
    else{
        return fun1(arr, n-1, sm - arr[n-1]) + fun1(arr, n-1, sm);
    }
}

// Memoization
int memo[102][102];
int fun2(int *arr, int n, int sm){
    if(n == 0 and sm != 0){
        return 0;
    }
    if(sm == 0){
        return 1;
    }
    if(memo[n][sm] != -1){
        return memo[n][sm];
    }
    if(arr[n-1] > sm){
        memo[n][sm] = fun2(arr, n-1, sm);
        return memo[n][sm];
    }
    else{
        memo[n][sm] = fun2(arr, n-1, sm-arr[n-1]) + fun2(arr, n-1, sm);
        return memo[n][sm];
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 6, 1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target_diff = 2;
    int sm = 0;
    for(int i = 0; i<n; i++){
        sm+=arr[i];
    }
    int find = (sm + target_diff)/2;
    cout<<fun(arr, n, find)<<endl;
    cout<<fun1(arr, n, find)<<endl;
    memset(memo, -1, sizeof(memo));
    cout<<fun2(arr, n, find);
}