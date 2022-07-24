/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int findPos(vector<int> inorder, int ele, int n){
    for(int i=0; i<n; i++){
        if(inorder[i] == ele)
            return i;
    }
    return -1;
}

TreeNode<int> *solve(vector<int> &inorder, vector<int> &preorder, int &index, int start, int end, int n){
    if(index>=n || start>end)
        return NULL;
    int ele = preorder[index];
    index++;
    int pos = findPos(inorder, ele, n);
    TreeNode<int> *node = new TreeNode<int>(ele);
    node->left= solve(inorder, preorder, index, start, pos-1, n);
    node->right = solve(inorder, preorder, index, pos+1, end, n);
    return node;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    int n = preorder.size();
    int index = 0;
    return solve(inorder, preorder, index, 0, n-1, n);
}