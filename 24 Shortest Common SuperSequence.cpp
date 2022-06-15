#include<bits/stdc++.h>
using namespace std;

int fun(string s1, string s2, int n, int m){
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < m+1; j++){
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
    
    return n+m-dp[n][m];
}

int main(){
    string S1 = "abckjnsdksdkdgh";
    string S2 = "abesjdnksddl";
    cout<<fun(S1, S2, S1.length(), S2.length());
}
