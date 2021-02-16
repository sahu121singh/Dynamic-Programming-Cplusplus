#include<bits/stdc++.h>
using namespace std;

// check whether A is subset of B or not
bool fun(string s1, string s2, int n, int m){
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < m+1; j++){
            if(i==0 || j==0){
                continue;
            }
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < m+1; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    if(dp[n][m] == n){
        return true;
    }
    return false;
}

int main(){
    string S1 = "AXY";
    string S2 = "ADXCPY";
    cout<<fun(S1, S2, S1.length(), S2.length());
}