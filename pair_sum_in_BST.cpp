/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
void findInorder(BinaryTreeNode<int> *root, vector<int> &in){
    if(root == NULL)
        return;
    findInorder(root->left, in);
    in.push_back(root->data);
    findInorder(root->right, in);
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    vector<int> in;
    findInorder(root, in);
    int low = 0, high = in.size()-1;
    while(low<high){
        int sum = in[low]+in[high];
        if(k == sum)
            return true;
        else if(k>sum)
            low++;
        else
            high--;
    }
    return false;
}