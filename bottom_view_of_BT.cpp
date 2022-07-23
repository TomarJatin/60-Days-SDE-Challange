#include<bits/stdc++.h>
/*************************************************************
 
    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> * root){
    vector<int> ans;
    if(root == NULL)
        return ans;
    map<int, int> mp;
    queue<pair<int, BinaryTreeNode<int> *>> q;
    q.push(make_pair(0, root));
    while(!q.empty()){
        pair<int, BinaryTreeNode<int> *> temp = q.front();
        q.pop();
        int ld = temp.first;
        BinaryTreeNode<int> *node = temp.second;
        mp[ld] = node->data;
        if(node->left)
            q.push(make_pair(ld-1, node->left));
        if(node->right)
            q.push(make_pair(ld+1, node->right));
    }
    for(auto it: mp)
        ans.push_back(it.second);
    return ans;
}
