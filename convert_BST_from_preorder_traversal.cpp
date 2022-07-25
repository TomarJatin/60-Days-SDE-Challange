#include<bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int>* solve(vector<int> &preorder, int &index, int min, int max){
    if(index<preorder.size() && preorder[index]>min && preorder[index]<max){
        TreeNode<int>* node = new TreeNode<int>(preorder[index++]);
        node->left = solve(preorder, index, min, node->data);
        node->right = solve(preorder, index, node->data, max);
        return node;
    }
    else
        return NULL;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int index = 0;
    return solve(preOrder, index, INT_MIN, INT_MAX);
}