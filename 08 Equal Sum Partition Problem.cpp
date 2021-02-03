#include<bits/stdc++.h>
using namespace std;

bool fun(int *arr, int n, int sm){
    bool dp[n+1][sm+1];
    
    for(int j = 0; j < sm+1; j++){
        dp[0][j] = false;
    }
    
    for(int i = 0; i < n+1; i++){
        dp[i][0] = true;
    }
    
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < sm+1; j++){
            
            if(arr[i-1] > j){
                dp[i][j] =  dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
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

bool fun1(int arr[], int n, int sm){
    if(sm != 0 and n==0){
        return false;
    }
    if(sm == 0 or n == 0){
        return true;
    }
    
    if(arr[n-1] > sm){
        return fun1(arr, n-1, sm);
    }
    else{
        return fun1(arr, n-1, sm-arr[n-1]) || fun1(arr, n-1, sm);
    }
}


int main(){
    int arr[] = {2, 1, 7, 8, 10};
    int sm = 0;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; i++){
        sm += arr[i];
    }
    if(sm%2){
        cout<<"Not possible of equal sum partition";
    }
    else{
        cout<<fun1(arr, n, sm/2);
    }
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
