#include<bits/stdc++.h>
using namespace std;

int fun(int e, int f){
    if(f == 0 || f == 1){
        return f;
    }
    if(e == 1){
        return f;
    }
    int mn = INT_MAX;
    for(int k = 1; k <= f; k++){
        int temp = 1 + max(fun(e-1, k-1), fun(e, f-k));
        mn = min(mn, temp);
    }
    return mn;
}

int main(){
    int f = 36;
    int e = 2;
    cout<<fun(e, f);
}