/************************************************************

    Following is the TreeNode class structure.

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

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int>* cur = root;
    while(cur){
        if(cur->left){
            TreeNode<int> *pred = cur->left;
            while(pred->right)
                pred = pred->right;
            pred->right = cur->right;
            cur->right = cur->left;
        }
        cur=cur->right;
    }
    cur = root;
    while(cur){
        cur->left = NULL;
        cur=cur->right;
    }
    return root;
}