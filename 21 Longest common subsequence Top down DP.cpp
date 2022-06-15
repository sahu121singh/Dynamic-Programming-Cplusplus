#include<bits/stdc++.h>
using namespace std;

int fun(string A, string B, int N, int M){
    int dp[N+1][M+1];
    memset(dp, 0, sizeof(dp));
    
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < M+1; j++){
            if(A[i-1] == B[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    for(int i = 0; i < N+1; i++){
        for(int j = 0; j < M+1; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[N][M];
}

int main(){
    string S1 = "abcdgh";
    string S2 = "abedfha";
    cout<<fun(S1, S2, S1.length(), S2.length())<<endl;
}
