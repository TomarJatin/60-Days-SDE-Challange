bool findpath(TreeNode* root, int B, vector<int> &ans){
    if(root == NULL)
    return false;
    ans.push_back(root->val);
    if(root->val == B)
    return true;
    bool left = findpath(root->left, B, ans);
    bool right = findpath(root->right, B, ans);
    if(left || right)
    return true;
    ans.pop_back();
    return false;
}
 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    bool check = findpath(A, B, ans);
    return ans;
}