#include<bits/stdc++.h>
using namespace std;

unordered_map<string, bool> memo;
bool fun(string a, string b){
    if(a.compare(b) == 0){
        return true;
    }
    if(a.length() <= 1){
        return false;
    }
    
    string key = a;
    key.push_back(' ');
    key.append(b);
    
    if(memo.find(key) != memo.end()){
        return memo[key];
    }
    
    bool flag = false;
    int n = a.length();
    
    for(int i = 1; i < n; i++){
        if((fun(a.substr(0, i), b.substr(n-i, i)) && fun(a.substr(i, n-i), b.substr(0, n-i))) || (fun(a.substr(0, i), b.substr(0, i)) && fun(a.substr(i, n-i), b.substr(i, n-i)))){
            flag = true;
            break;
        }
    }
    memo[key] = flag;
    return flag;
}



int main(){
    string a = "great";
    string b = "rgeat";
    memo.clear();
    if(a.length() != b.length()){
        cout<<false;
    }
    if(a.length() == 0 && b.length()==0){
        cout<<false;
    }
    else{
        cout<<fun(a, b);
    }
}