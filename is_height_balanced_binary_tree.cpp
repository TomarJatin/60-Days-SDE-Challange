#include<bits/stdc++.h>
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
pair<bool, int> solve(BinaryTreeNode<int>* root){
    if(root == NULL)
        return make_pair(true, 0);
    
    pair<bool, int> left = solve(root->left);
    pair<bool, int> right = solve(root->right);
    
    int height = max(left.second, right.second)+1;
    bool check;
    if(left.first && right.first && abs(right.second-left.second)<=1)
        check = true;
    else
        check = false;
    return make_pair(check, height);
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    pair<bool, int> ans = solve(root);
    return ans.first;
}