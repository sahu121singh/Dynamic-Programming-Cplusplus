#include<bits/stdc++.h>
using namespace std;

// -------------------------------------------------- dp 
int fun2(string A, string B, int N, int M){
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

// -------------------------------------------------- memoiztion
int memo[101][101];
int fun1(string A, string B, int N, int M){
    if(N == 0 or M == 0){
        return 0;
    }
    if(memo[N][M] != -1){
        return memo[N][M];
    }
    if(A[N-1] == B[M-1]){
        memo[N][M] = 1 + fun1(A, B, N-1, M-1);
    }
    else{
        memo[N][M] = max(fun1(A, B, N-1, M), fun1(A, B, N, M-1));
    }
    return memo[N][M];
}


// -------------------------------------------------- recursive
int fun(string A, string B, int N, int M){
    if(N == 0 or M == 0){
        return 0;
    }
    if(A[N-1] == B[M-1]){
        return 1 + fun(A, B, N-1, M-1);
    }
    else{
        return max(fun(A, B, N-1, M), fun(A, B, N, M-1));
    }
}

int main(){
    string S1 = "abcdgh";
    string S2 = "abedfha";
    cout<<fun(S1, S2, S1.length(), S2.length());
    
    memset(memo, -1, sizeof(memo));
    cout<<fun1(S1, S2, S1.length(), S2.length())<<endl;
    for(int i = 0; i < S1.length()+1; i++){
        for(int j = 0; j < S2.length()+1; j++){
            cout<<memo[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<fun2(S1, S2, S1.length(), S2.length())<<endl;
}
