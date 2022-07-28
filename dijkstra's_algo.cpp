vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<vector<pair<int, int>>> adj(vertices);
    for(int i=0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    
    vector<int> dis(vertices, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[source] = 0;
    pq.push({0, source});
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        for(auto it: adj[node]){
            if(dis[it.second]>dis[node]+it.first){
                dis[it.second] = dis[node]+it.first;
                pq.push({dis[it.second], it.second});
            }
        }
    }
    return dis;
}
