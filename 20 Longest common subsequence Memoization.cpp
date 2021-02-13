#include<bits/stdc++.h>
using namespace std;

int memo[101][101];
int fun(string A, string B, int N, int M){
    if(N == 0 or M == 0){
        return 0;
    }
    if(memo[N][M] != -1){
        return memo[N][M];
    }
    if(A[N-1] == B[M-1]){
        memo[N][M] = 1 + fun(A, B, N-1, M-1);
    }
    else{
        memo[N][M] = max(fun(A, B, N-1, M), fun(A, B, N, M-1));
    }
    return memo[N][M];
}

int main(){
    string S1 = "abcdgh";
    string S2 = "abedfha";
    memset(memo, -1, sizeof(memo));
    cout<<fun(S1, S2, S1.length(), S2.length())<<endl;
    for(int i = 0; i < S1.length()+1; i++){
        for(int j = 0; j < S2.length()+1; j++){
            cout<<memo[i][j]<<" ";
        }
        cout<<endl;
    }
}