#include<bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans;
    if(root == NULL)
        return ans;
    map<int, int> mp;
    queue<pair<int, TreeNode<int> *>> q;
    q.push(make_pair(0, root));
    while(!q.empty()){
        pair<int, TreeNode<int> *> temp = q.front();
        q.pop();
        int hd = temp.first;
        TreeNode<int> *node = temp.second;
        if(mp.find(hd) == mp.end())
            mp[hd] = node->val;
        if(node->left)
            q.push(make_pair(hd-1, node->left));
        if(node->right)
            q.push(make_pair(hd+1, node->right));
    }
    for(auto it: mp)
        ans.push_back(it.second);
    return ans;
}