#include<bits/stdc++.h>
using namespace std;

int fun(int *arr, int n, int sm){
    int dp[n+1][sm+1];
    
    for(int j = 0; j < sm+1; j++){
        dp[0][j] = 0;
    }
    
    for(int i = 0; i < n+1; i++){
        dp[i][0] = 1;
    }
    
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < sm+1; j++){
            
            if(arr[i-1] > j){
                dp[i][j] =  dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j - arr[i-1]] + dp[i-1][j];
            }
        }
    }
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < sm+1; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return dp[n][sm];
}

int fun1(int arr[], int n, int sm){
    if(sm != 0 and n==0){
        return 0;
    }
    if(sm == 0 or n == 0){
        return 1;
    }
    
    if(arr[n-1] > sm){
        return fun1(arr, n-1, sm);
    }
    else{
        return fun1(arr, n-1, sm-arr[n-1]) + fun1(arr, n-1, sm);
    }
}


int main(){
    int arr[] = {2, 3, 5, 6, 8, 10};
    int sm = 10;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<fun1(arr, n, sm);
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