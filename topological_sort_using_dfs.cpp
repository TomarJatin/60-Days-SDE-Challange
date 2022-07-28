#include<bits/stdc++.h>
void toposort(vector<vector<int>> &adj, stack<int> &st, int node, vector<int> &vis){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it])
        toposort(adj, st, it, vis);
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int n, int e)  {
    stack<int> st;
    vector<vector<int>> adj(n);
    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
    }
    vector<int> vis(n, 0);
    for(int i=0; i<n; i++){
        if(!vis[i])
            toposort(adj, st, i, vis);
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}