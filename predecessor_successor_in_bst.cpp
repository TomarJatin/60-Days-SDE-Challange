/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int pre = -1, suc = -1;
    BinaryTreeNode<int>* temp = root;
    while(temp->data != key){
        if(temp->data > key){
            suc = temp->data;
            temp = temp->left;
        }
        else{
             pre = temp->data;
            temp = temp->right;
        }
    }
    BinaryTreeNode<int>* leftT = temp->left;
    while(leftT){
        pre = leftT->data;
        leftT = leftT->right;
    }
    BinaryTreeNode<int>* rightT = temp->right;
    while(rightT){
        suc = rightT->data;
        rightT = rightT->left;
    }
    pair<int, int> ans = make_pair(pre, suc);
    return ans;
}
