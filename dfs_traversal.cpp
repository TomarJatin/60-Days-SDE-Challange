void dfs(vector<vector<int>> &adj, int node, vector<int> &vis, vector<int> &temp){
    vis[node] = 1;
    temp.push_back(node);
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(adj, it, vis, temp);
        }
    }
}

vector<vector<int>> depthFirstSearch(int n, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(n);
    for(int i=0; i<E; i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    
    vector<int> vis(n, 0);
    vector<vector<int>> ans;
    
    for(int i=0; i<n; i++){
        if(!vis[i]){
            vector<int> temp;
            dfs(adj, i, vis, temp);
            ans.push_back(temp);
        }
    }
    return ans;
}