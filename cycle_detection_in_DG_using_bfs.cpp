#include<bits/stdc++.h>
int dfs(vector<vector<int>> &adj, int node, vector<int> &vis, vector<int> &dfsvis){
    vis[node] = 1;
    dfsvis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            if(dfs(adj, it, vis, dfsvis))
                return 1;
        }
        if(dfsvis[it])
            return 1;
    }
    dfsvis[node] = 0;
    return 0;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<vector<int>> adj(n+1);
    int m = edges.size();
    for(int i=0; i<m; i++){
        int u=edges[i].first;
        int v=edges[i].second;
        
        adj[u].push_back(v);
    }
    
    vector<int> in(n+1, 0);
    for(int i=1; i<=n; i++){
        for(auto it: adj[i])
            in[it]++;
    }
    queue<int> q;
    for(int i=1; i<=n; i++)
        if(in[i] == 0) q.push(i);
    
    int count = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        count++;
        for(auto it: adj[node]){
            in[it]--;
            if(in[it] == 0)
                q.push(it);
        }
        if(count==n)
            return false;
    }
    return true;
}