#include<bits/stdc++.h>
using namespace std;

int memo[101][101];
int fun(int *arr, int i, int j){
    if(i >= j){
        return 0;
    }
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    int ans = INT_MAX;
    for(int k = i; k < j; k++){
        int temp = fun(arr, i, k) + fun(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
        
        ans = min(ans, temp);
    }
    memo[i][j] = ans;
    return ans;
}

int main(){
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    memset(memo, -1, sizeof(memo));
    cout<<fun(arr, 1, n-1)<<"\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<memo[i][j]<<" ";
        }
        cout<<"\n";
    }
    
}