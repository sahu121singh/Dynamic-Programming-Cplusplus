#include<bits/stdc++.h>
using namespace std;

// k = i      to     k = j-1                 (i, k) + (k+1, j)
// k = i+1    to     k = j                  (i, k-1) + (k, j)

bool ispalindrom(string s, int srt, int end){
    string res = "";
    string org = "";
    for(int i = srt; i <= end; i++){
        res = s[i] + res;
        org += s[i];
    }
    return org == res;
}

int memo[101][101];
int fun(string s, int i, int j){
    if(i >= j){
        return 0;
    }
    if(ispalindrom(s, i, j)){
        return 0;
    }
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    int ans = INT_MAX;
    for(int k = i; k < j; k++){
        int left, right;
        if(memo[i][k] != -1){
            left = memo[i][k];
        }
        else{
            left = fun(s, i, k);
            memo[i][k] = left;
        }
        if(memo[k+1][j] != -1){
            right = memo[k+1][j];
        }
        else{
            right = fun(s, k+1, j);
            memo[k+1][j] = right;
        }
        
        int temp = left + right + 1;
        ans = min(ans, temp);
    }
    return memo[i][j] = ans;
}

int main(){
    string s = "nitikn";
    int n = s.length();
    memset(memo, -1, sizeof(memo));
    cout<<fun(s, 0, n-1)<<"\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<memo[i][j]<<" ";
        }
        cout<<"\n";
    }
}