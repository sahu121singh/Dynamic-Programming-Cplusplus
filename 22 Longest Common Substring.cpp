#include<bits/stdc++.h>
using namespace std;

//dp or top_down
int fun(string A, string B, int N, int M){
    int dp[N+1][M+1];
    memset(dp, 0, sizeof(dp));
    
    int mx = 0;
    for(int i = 1; i < N+1; i++){
        for(int j = 1; j < M+1; j++){
            if(A[i-1] == B[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                mx = max(mx, dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < N+1; i++){
        for(int j = 0; j < M+1; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return mx;
}

// recursive
int mx1 = 0;
int fun1(string A, string B, int N, int M, int count){
    if(N==0 or M==0){
        return max(mx1, count);
    }
    if(A[N-1] == B[M-1]){
        count += 1;
        mx1 = max(mx1, count);
        return fun1(A, B, N-1, M-1, count);
    }
    else{
        count = 0;
        return max(fun1(A, B, N-1, M, count), fun1(A, B, N, M-1, count));
    }
}


/*  // memoization
int mx2 = 0;
int memo[101][101];

int fun2(string A, string B, int N, int M, int count){
    if(N == 0 || M == 0){
        return max(mx2, count);
    }
    if(memo[N][M] != -1){
        return max(mx2, memo[N][M]);
    }
    if(A[N-1] == B[M-1]){
        count += 1; 
        mx2 = max(mx2, count);
        memo[N][M] = max(mx2, fun2(A, B, N-1, M-1, count));
        return memo[N][M];
    }
    else{
        count = 0;
        memo[N][M] = max(fun2(A, B, N-1, M, count), fun2(A, B, N, M-1, count));
        return memo[N][M];
    }
}*/

int main(){
    string S1 = "abckjnsdksdkdgh";
    string S2 = "abesjdnksddl";
    cout<<fun(S1, S2, S1.length(), S2.length())<<endl;
    cout<<fun1(S1, S2, S1.length(), S2.length(), 0)<<endl;
    
    /*
    memset(memo, -1, sizeof(memo));
    cout<<max(mx2, fun2(S1, S2, S1.length(), S2.length(), 0))<<endl;
    for(int i = 0; i < S1.length() + 1; i++){
        for(int j = 0; j < S2.length() + 1; j++){
            cout<<memo[i][j]<<" ";
        }
        cout<<endl;
    }*/
}

    //string S1 = "abckjnsdksdkdgh";
    //string S2 = "abesjdnksddlkslabcdfha";
