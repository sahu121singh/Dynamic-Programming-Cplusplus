#include<bits/stdc++.h>
using namespace std;

int fun_dp(int *val, int *wt, int n, int w){
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


int memo[1001][1001];
int fun_memo(int val[], int w[], int n, int wt){
    if(n==0 || wt == 0){
        return 0;
    }
    if(memo[n][wt] != -1){
        return memo[n][wt];
    }
    if(w[n-1] <= wt){
        memo[n][wt] = max(val[n-1] + fun_memo(val, w, n-1, wt-w[n-1]), fun_memo(val, w, n-1, wt));
    }
    else{
        memo[n][wt] = fun_memo(val, w, n-1, wt);
    }
    return memo[n][wt];
}


int fun(vector<int> val, vector<int> w, int n, int wt){
    // no. of available items are zero or current capacity of bag is zero
    if(n==0 || wt == 0){
        return 0;
    }
    // weight of current item (n-1 th item) is less than or equal to current capacity
    if(w[n-1] <= wt){
        // max(value_of_current_item + value_of_next_item, value_of_next_item (leave current item))
        return max(val[n-1] + fun(val, w, n-1, wt-w[n-1]), fun(val, w, n-1, wt));
    }
    else{// weight of current item (n-1 th item) is greater than current capacity
        // go to next item
        return fun(val, w, n-1, wt);
    }
}

int main(){
    vector<int> w = {2, 3, 4, 5}; // list of weights of each item
    vector<int> val = {1, 2, 5, 6}; // list of values of each item
    int wt = 8; // max capacity of bag
    int n = 4; // no. of available items
    cout<<fun(val, w, n, wt);
    
    memset(dp, -1, sizeof(memo));
    cout<<fun_memo(val, w, 4, 8)<<endl<<endl;
    for(int i = 0; i <= 4; i++){
        for(int j = 0; j <= 8; j++){
            cout<<memo[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<fun_dp(val, wt, n, w);
}
