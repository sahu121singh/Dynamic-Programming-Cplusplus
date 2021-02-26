#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    struct Node *left;
    struct Node *right;
};

struct Node *create(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> val = data;
    temp -> left = NULL;
    temp ->right = NULL;
}

int fun(struct Node *root, int &res){
    if(root == NULL){
        return 0;
    }
    int l = fun(root->left, res);
    int r = fun(root->right, res);
    
    int temp = max(max(l, r) + root-> val, root->val);
    int ans = max(l+r+root->val, temp);
    res = max(ans, res);
    return temp;
}

int main(){
    struct Node *root = create(1);
    
    root->left = create(2);
    
    root->left->left = create(4);
    root->left->left->right = create(7);
    root->left->left->right->left = create(9);
    
    root->left->right = create(5);
    root->left->right->left = create(8);
    
    root->right = create(3);
    root->right->right = create(6);
    
    int res = INT_MIN;
    //cout<<fun(root, res)<<"\n";
    fun(root, res);
    cout<<res;
}


