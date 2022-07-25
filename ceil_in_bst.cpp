/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
    BinaryTreeNode<int> *cur = node;
    int ans = -1;
    while(cur){
        if(cur->data < x)
            cur = cur->right;
        else{
            ans = cur->data;
            cur = cur->left;
        }
    }
    return ans;
}