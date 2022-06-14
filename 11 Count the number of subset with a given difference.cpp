#include<bits/stdc++.h>
using namespace std;

int fun(int arr[], int n, int sm){
    
    int dp[n+1][sm+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    
    for(int i = 1; i<n+1; i++){
        for(int j = 0; j < sm+1; j++){
            if(j == 0){
                dp[i][j] = 1;
            }
            else if(arr[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
        }
    }
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j < sm+1; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return dp[n][sm];
}

int fun1(int arr[], int n, int sm){
    if(n==0 and sm != 0){
        return 0;
    }
    if(n == 0 or sm == 0){
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
    int arr[] = {1, 1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int sm = 0;
    for(int i = 0; i < n; i++){
        sm += arr[i];
    }
    
    int diff = 1;
    
    int find = (diff + sm)/2;
    cout<<fun(arr, n, find);
}


/*
=> sum1-sum2=diff
=> sum1-(sum-sum1)=diff
=> 2*sum1= diff+ sum
=> sum1= (diff+sum)/2;
*/
