#include<bits/stdc++.h>
using namespace std;

int fun(vector<int> val, vector<int> w, int n, int wt){
    if(n==0 || wt == 0){
        return 0;
    }
    // weight of current item (n-1 th item) is less than or equal to current capacity
    if(w[n-1] <= wt){
        // max(value_of_current_item + value_of_next_item, value_of_next_item (leave current item))
        return max(val[n-1] + fun(val, w, n-1, wt-w[n-1]), fun(val, w, n-1, wt));
    }
    else{// weight of current item (n-1 th item) is greater than current capacity
        // go to next item
        return fun(val, w, n-1, wt);
    }
}

int main(){
    vector<int> w = {2, 3, 4, 5}; // list of weights of each item
    vector<int> val = {1, 2, 5, 6}; // list of values of each item
    int wt = 8; // max capacity of bag
    int n = 4; // no. of available items
    cout<<fun(val, w, n, wt);
}
