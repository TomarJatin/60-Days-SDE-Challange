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
bool solve(BinaryTreeNode<int> *root, int min, int max){
    if(root == NULL) return true;
    if(root->data < min || root->data>max){
        return false;
    }
    bool left = solve(root->left, min, root->data);
        bool right = solve(root->right, root->data, max);
        return (left && right);
    
}

bool validateBST(BinaryTreeNode<int> *root) {
    return solve(root, INT_MIN, INT_MAX);
}