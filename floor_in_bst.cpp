/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    int ans = -1;
    TreeNode<int> *temp = root;
    while(temp){
        if(temp->val > X)
            temp=temp->left;
        else{
            ans = temp->val;
            temp = temp->right;
        }
    }
    
    return ans;
}