/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
int getPos(vector<int> &inorder, int& ele, int& n){
    for(int i=0; i<n; i++){
        if(inorder[i] == ele)
            return i;
    }
    return -1;
}

TreeNode<int>* solve(vector<int> &inorder, vector<int> &postorder, int &index, int start, int end, int &n){
    if(index < 0 || start>end)
        return NULL;
    int ele = postorder[index];
    index--;
    TreeNode<int>* node = new TreeNode<int>(ele);
    int pos = getPos(inorder, ele, n);
    node->right = solve(inorder, postorder, index, pos+1, end, n);
    node->left = solve(inorder, postorder, index, start, pos-1, n);
    return node;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
    int n= postOrder.size();
	int index = n-1;
    return solve(inOrder, postOrder, index, 0, n-1, n);
}
