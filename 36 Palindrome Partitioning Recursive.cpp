#include<bits/stdc++.h>
using namespace std;

// i = 0       j = n - 1     k = i   to  k = j-1        (i, k)    +  (k+1, j)
// i = 0       j = n - 1     k = i+1 to  k = j          (i, k-1)  +  (k, j)

bool ispalindrom(string s, int srt, int end){
    string res = "";
    string org = "";
    for(int i = srt; i <= end; i++){
        res = s[i] + res;
        org += s[i];
    }
    return res == org;
}

int fun(string s, int i, int j){
    if(i >= j){
        return 0;
    }
    if(ispalindrom(s, i, j)){
        return 0;
    }
    int ans = INT_MAX;
    for(int k = i; k < j; k++){
        int temp = fun(s, i, k) + fun(s, k+1, j) + 1;
        
        ans = min(ans, temp);
    }
    return ans;
}
int main(){
    string s = "nitikn";
    int n = s.length();
    cout<<fun(s, 0, n-1);
}