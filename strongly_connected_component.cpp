#include<bits/stdc++.h>
void dfs(vector<vector<int>> &adj, vector<int> &vis, stack<int> &st, int node){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it])
            dfs(adj, vis, st, it);
    }
    st.push(node);
}

void revDfs(vector<vector<int>> &adj, vector<int> &vis, vector<int> &ans, int node){
    vis[node] = 1;
    ans.push_back(node);
    for(auto it: adj[node])
        if(!vis[it]) revDfs(adj, vis, ans, it);
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    stack<int> st;
    vector<vector<int>> adj(n);
    for(auto it: edges){
        int u=it[0];
        int v=it[1];
        adj[u].push_back(v);
    }
    
    vector<int> vis(n, 0);
    for(int i=0; i<n; i++){
        if(!vis[i])
            dfs(adj, vis, st, i);
    }
    vector<vector<int>> transpose(n);
    for(int i=0; i<n; i++){
        vis[i] = 0;
        for(auto it: adj[i])
            transpose[it].push_back(i);
    }
    vector<vector<int>> ans;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        vector<int> temp;
        if(!vis[node])
            revDfs(transpose, vis, temp, node);
        ans.push_back(temp);
    }
    return ans;
}