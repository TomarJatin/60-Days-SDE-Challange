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
pair<int, int> solve(TreeNode<int> *root){
    if(root == NULL)
        return make_pair(0, 0);
    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);
    int op = left.second+right.second;
    int diameter=max(left.first, max(right.first, op));
    int height = max(left.second, right.second)+1;
    return make_pair(diameter, height);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	pair<int, int> ans = solve(root);
    return ans.first;
}
