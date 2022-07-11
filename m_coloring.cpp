bool isSafe(vector<vector<int>> &mat, int &node, vector<int> &color, int &n, int col){
    for(int k=0; k<n; k++){
        if(k!=node && mat[node][k] == 1 && color[k] == col)
            return false;
    }
    return true;
}

bool solve(vector<vector<int>> &mat, int &m, int &n, vector<int> &color, int node){
    if(node == n){
        return true;
    }
    for(int i=1; i<=m; i++){
        if(isSafe(mat, node, color, n, i)){
            color[node] = i;
            if(solve(mat, m, n, color, node+1)) return true;
            color[node] = 0;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int n = mat.size();
    vector<int> color(n, 0);
    if(solve(mat, m, n, color, 0))
        return "YES";
    return "NO";
}