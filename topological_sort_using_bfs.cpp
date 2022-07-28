#include<bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &edges, int n, int e)  {
    stack<int> st;
    vector<vector<int>> adj(n);
    for(auto it: edges){
        int u = it[0];
        int v = it[1];
        adj[u].push_back(v);
    }
    vector<int> in(n, 0), ans;
    for(int i=0; i<n; i++){
        for(auto it: adj[i])
            in[it]++;
    }
    queue<int> q;
    for(int i=0; i<n; i++)
        if(in[i] == 0) q.push(i);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it: adj[node]){
            in[it]--;
            if(in[it] == 0)
                q.push(it);
        }
    }
    return ans;
}