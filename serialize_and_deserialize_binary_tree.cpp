#include<bits/stdc++.h>
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

void serialize(TreeNode<int> *root, string &ans){
    if(root==NULL){
        ans = ans + to_string(-1);
        return;
    }
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()){
        TreeNode<int> *cur = q.front();
        q.pop();
        
        if(cur==NULL){
            ans=ans+to_string(-1)+",";
            continue;
        }
        ans=ans+to_string(cur->data)+",";
        q.push(cur->left);
        q.push(cur->right);
    }
}
string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
    string ans = "";
    serialize(root,ans);
//     cout<<ans<<endl;
    return ans;
}

TreeNode<int>* deserializeTree(string &serialized)
{
 //    Write your code here for deserializing the tree
    int i=0,n=serialized.size();
    if(serialized=="-1")
        return NULL;
    
    string t="";
    while(serialized[i]!=','){
        t=t+serialized[i];
        i++;
    }
    i++;
    
    TreeNode<int> *root = new TreeNode<int> (stoi(t));
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty() && i<n){
        TreeNode<int>* cur = q.front();
        q.pop();
        
        string t1="";
        while(i<n && serialized[i]!=','){
            t1=t1+serialized[i];
            i++;
        }
        i++;
        if(t1!=""){
            if(t1!="-1"){
                cur->left = new TreeNode<int> (stoi(t1));
                q.push(cur->left);
            }
        }
        
        string t2="";
        while(i<n && serialized[i]!=','){
            t2=t2+serialized[i];
            i++;
        }
        i++;
        if(t2!=""){
            if(t2!="-1"){
                cur->right = new TreeNode<int> (stoi(t2));
                q.push(cur->right);
            }
        }
    }
    
    return root;
}


