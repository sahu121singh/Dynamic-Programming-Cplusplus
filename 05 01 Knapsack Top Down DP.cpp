#include<bits/stdc++.h>
using namespace std;

int fun(int *val, int *wt, int n, int w){
    vector<vector<int>> dp(n+1, vector<int> (w+1, 0));
    
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < w+1; j++){
            if(wt[i-1] > j){
                dp[i][j] =  dp[i-1][j];
            }
            else{
                dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]], dp[i-1][j]);
            }
        }
    }
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < w+1; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return dp[n][w];
}


int main(){
    int wt[] = {2, 3, 4, 5};
    int val[] = {1, 2, 5, 6};
    int w = 8, n = 4;
    cout<<fun(val, wt, n, w);
}


/*
def fun(val, wt, n, w):
    if n == 0 or w == 0:
        return 0
    
    if wt[n-1] <= w:
        return max(val[n-1] + fun(val, wt, n-1, w- wt[n-1]), fun(val, wt, n-1, w))
    
    else:
        return fun(val, wt, n-1, w)

*/
