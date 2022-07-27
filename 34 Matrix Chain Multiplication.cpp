#include<bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------------------ Memoization
int memo[101][101];
int fun1(int *arr, int i, int j){
    if(i >= j){
        return 0;
    }
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    int ans = INT_MAX;
    for(int k = i; k < j; k++){
        int temp = fun1(arr, i, k) + fun1(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
        
        ans = min(ans, temp);
    }
    memo[i][j] = ans;
    return ans;
}

// ------------------------------------------------------------------------ Recursive
// i = 1, j = len - 1

// k = i, k < j           (i, k) + (k+1, j)
// k = i+1, k<=j          (i, k-1) + (k, j)

int fun(int *arr, int i, int j){
    if(i >= j){
        return 0;
    }
    int ans = INT_MAX;
    for(int k = i; k < j; k++){
        int temp = fun(arr, i, k) + fun(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
        if(temp < ans){
            ans = temp;
        }
    }
    return ans;
}

int main(){
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<fun(arr, 1, n-1);
    
    memset(memo, -1, sizeof(memo));
    cout<<fun1(arr, 1, n-1)<<"\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<memo[i][j]<<" ";
        }
        cout<<"\n";
    }
}


