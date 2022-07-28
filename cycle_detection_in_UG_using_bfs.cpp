#include<bits/stdc++.h>
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
            queue<pair<int, int>> q;
            vis[i] = 1;
            q.push({i, -1});
            while(!q.empty()){
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();
                for(auto it: adj[node]){
                    if(!vis[it]){
                        q.push({it, node});
                        vis[it] = 1;
                    }
                    else if(vis[it] && it != parent)
                        return "Yes";
                }
            }
        }
    }
    return "No";
}
