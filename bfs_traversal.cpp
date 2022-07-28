#include<bits/stdc++.h>
void bfs(vector<vector<int>> &adj, vector<int> &ans, vector<int> &vis, int node){
    vis[node] = 1;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int frontnode = q.front();
        q.pop();
        ans.push_back(frontnode);
        for(auto it: adj[frontnode]){
            if(!vis[it]){
                q.push(it);
                vis[it] = 1;
            }
        }
    }
}

vector<int> BFS(int n, vector<pair<int, int>> edges)
{
    vector<vector<int>> adj(n);
    vector<int> ans;
    vector<int> vis(n, 0);
    int e = edges.size();
    for(int i=0; i<e; i++){
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=0; i<n; i++)
        sort(adj[i].begin(), adj[i].end());
    
    for(int i=0; i<n; i++){
        if(!vis[i])
            bfs(adj, ans, vis, i);
    }
    return ans;
}