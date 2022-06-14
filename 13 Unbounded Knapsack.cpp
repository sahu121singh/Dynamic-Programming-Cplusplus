#include<bits/stdc++.h>
using namespace std;

int fun(int *val, int *wt, int n, int w){
    int dp[n+1][w+1];
    memset(dp, 0, sizeof(dp));
    
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < w+1; j++){
            if(wt[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);
            }
        }
    }
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < w+1; j++){
            cout<<dp[i][j] <<" ";
        }
        cout<<endl;
    }
    return dp[n][w];
}

int fun1(int *val, int *wt, int n, int w){
    if(n == 0 or w == 0){
        return 0;
    }
    if(wt[n-1] > w){
        return fun1(val, wt, n-1, w);
    }
    else{
        return max(val[n-1] + fun1(val, wt, n, w-wt[n-1]), fun1(val, wt, n-1, w));
    }
}

int memo[102][102];
int fun2(int *val, int *wt, int n, int w){
    if(n==0 or w == 0){
        return 0;
    }
    if(memo[n][w] != -1){
        return memo[n][w];
    }
    if(wt[n-1] > w){
        memo[n][w] = fun2(val, wt, n-1, w);
        return memo[n][w];
    }
    else{
        memo[n][w] = max(val[n-1] + fun2(val, wt, n, w-wt[n-1]), fun2(val, wt, n-1, w));
        return memo[n][w];
    }
}


int main(){
    int val[] = {1, 2, 5, 6};
    int wt[] = {2, 3, 4, 5};
    int n = sizeof(val)/sizeof(val[0]);
    int w = 8;
    cout<<fun(val, wt, n, w)<<endl;
    cout<<fun1(val, wt, n, w)<<endl;
    memset(memo, -1, sizeof(memo));
    cout<<fun2(val, wt, n, w);
}
