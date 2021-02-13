#include<bits/stdc++.h>
using namespace std;

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
}