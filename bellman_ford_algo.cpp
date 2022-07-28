int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    int inf = 1000000000;
    vector<int> dist(n+1, inf);
    dist[src] = 0;
    
    for(int i=1; i<=n-1; i++){
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if(dist[u]!=inf)
            if(dist[u]+w < dist[v])
                dist[v] = dist[u]+w;
        }
    }
    return dist[dest];
}