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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if(root == NULL)
        return ans;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    bool LeftToRight = true;
    while(!q.empty()){
        int n= q.size();
        vector<int> temp(n);
        for(int i=0; i<n; i++){
            BinaryTreeNode<int> *node = q.front();
            q.pop();
            int index = LeftToRight ? i : n-i-1;
            temp[index] = node->data;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        LeftToRight = !LeftToRight;
        for(int i=0; i<n; i++){
            ans.push_back(temp[i]);
        }
    }
    return ans;
}
