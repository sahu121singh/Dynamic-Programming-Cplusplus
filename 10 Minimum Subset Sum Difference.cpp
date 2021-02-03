#include<bits/stdc++.h>
using namespace std;

int fun(int arr[], int n, int range){
    bool dp[n+1][range+1];
    memset(dp, 0, sizeof(dp));
    
    for(int j = 0; j < range+1; j++){
        dp[0][j] = 0;
    }
    
    for(int i = 0; i < n+1; i++){
        dp[i][0] = 1;
    }
    
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < range+1; j++){
            
            if(arr[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
            }
        }
    }
    
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < range+1; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    /*
    for(int j = 0; j < range/2 + 1; j++){
        if(dp[n][j] == 1){
            cout<<j<<" ";
        }
    }
    cout<<endl;
    */
    int mn = pow(10, 9) + 7;
    for(int j = 0; j < range/2 + 1; j++){
        if(dp[n][j] == 1){
            int sm = range - 2*j;
            if(sm < mn){
                mn = sm;
            }
        }
    }
    return mn;
}


int main(){
    int arr[] = {1, 2, 7};
    int sm = 0;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; i++){
        sm += arr[i];
    }
    
    cout<<fun(arr, n, sm);
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