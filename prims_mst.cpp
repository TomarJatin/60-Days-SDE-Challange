#include<bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<vector<pair<int, int>>> adj(n+1);
    for(auto it: g){
        int u = it.first.first;
        int v = it.first.second;
        int w = it.second;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> key(n+1, INT_MAX), parent(n+1);
    vector<bool> mst(n+1, false);
    parent[1] = -1;
    key[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    while(!q.empty()){
        int u = q.top().second;
        q.pop();
        mst[u] = true;
        for(auto it: adj[u]){
            int v = it.first;
            int w = it.second;
            if(!mst[v] && key[v]>w){
                key[v] = w;
                parent[v] = u;
                q.push({key[v], v});
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2; i<=n; i++){
        int u = parent[i];
        int v = i;
        int w = key[i];
        ans.push_back(make_pair(make_pair(u, v), w));
    }
    return ans;
}
