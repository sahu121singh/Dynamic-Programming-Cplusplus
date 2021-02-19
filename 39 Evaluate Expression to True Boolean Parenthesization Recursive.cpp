#include<bits/stdc++.h>
using namespace std;

int fun(string s, int i, int j, char tf){
    if(i > j){
        return 0;
    }
    if(i==j){
        if(tf == 'T') return s[i] == tf ? 1 : 0;
        
        if(tf == 'F') return s[i] == tf ? 1 : 0;
    }
    
    int ans = 0;
    for(int k = i+1; k < j; k+=2){
        int lt = fun(s, i, k-1, 'T');
        int lf = fun(s, i, k-1, 'F');
        int rt = fun(s, k+1, j, 'T');
        int rf = fun(s, k+1, j, 'F');
        
        if(s[k] == '&'){
            if(tf == 'T'){
                ans += lt*rt;
            }
            else{
                ans += (lt*rf + lf*rt + lf*rf);
            }
        }
        else if(s[k] == '^'){
            if(tf == 'T'){
                ans += (lt*rf + lf*rt);
            }
            else{
                ans += (lt*rt + lf*rf);
            }
        }
        else if(s[k] == '|'){
            if(tf == 'T'){
                ans += (lt*rt + lt*rf + lf*rt);
            }
            else{
                ans += lf*rf;
            }
        }
    }
    return ans;
}

int main(){
    string s = "T|F&T^F";
    int n = s.length();
    cout<<fun(s, 0, n-1, 'F');
}