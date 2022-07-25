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
TreeNode<int>* solve(vector<int> &arr, int start, int end){
    if(start>end)
        return NULL;
    int mid = (start+end+1)/2;
    TreeNode<int>* node = new TreeNode<int>(arr[mid]);
    node->left = solve(arr, start, mid-1);
    node->right = solve(arr, mid+1, end);
    return node;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    int index = arr.size()/2;
    return solve(arr, 0, n-1);
}