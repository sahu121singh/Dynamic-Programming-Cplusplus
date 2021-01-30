#include<bits/stdc++.h>
using namespace std;

int fun(vector<int> val, vector<int> w, int n, int wt){
    if(n==0 || wt == 0){
        return 0;
    }
    if(w[n-1] <= wt){
        return max(val[n-1] + fun(val, w, n-1, wt-w[n-1]), fun(val, w, n-1, wt));
    }
    else{
        return fun(val, w, n-1, wt);
    }
}

int main(){
    vector<int> w = {2, 3, 4, 5};
    vector<int> val = {1, 2, 5, 6};
    cout<<fun(val, w, 4, 8);
}