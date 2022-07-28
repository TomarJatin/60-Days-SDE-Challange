#include<bits/stdc++.h>

string dfs(vector<vector<int>> &adj, int node, vector<int> &vis, int parent){
    vis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            if(dfs(adj, it, vis, node) == "Yes")
                return "Yes";
        }
        else if(it != parent)
            return "Yes";
    }
    return "No";
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(n+1, 0);
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(dfs(adj, i, vis, -1) == "Yes")
                return "Yes";
        }
    }
    return "No";
}
