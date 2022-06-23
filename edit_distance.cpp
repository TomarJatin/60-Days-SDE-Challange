//memoization
int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp){
    if(i<0) return j+1;
    if(j<0) return i+1;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    if(s[i] == t[j])
        return dp[i][j] = solve(s, t, i-1, j-1, dp);
    else{
        int del = 1+solve(s, t, i-1, j, dp);
        int ins = 1+solve(s, t, i, j-1, dp);
        int rep = 1+solve(s, t, i-1, j-1, dp);
        return dp[i][j] = min(del, min(ins, rep));
    }
}

int editDistance(string str1, string str2)
{
    //write you code here
    int n = str1.size();
    int m = str2.size();
    //vector<vector<int>> dp(n, vector<int>(m, -1));
    //return solve(str1, str2, n-1, m-1, dp);
    
    // space optimization
    vector<int> prev(m+1, 0), cur(m+1, 0);
    for(int j=0; j<=m; j++) prev[j] = j;
    for(int i=1; i<=n; i++){
        cur[0] = i;
        for(int j=1; j<=m; j++){
            if(str1[i-1] == str2[j-1])
                cur[j] = prev[j-1];
            else{
                int del = 1+prev[j];
                int ins = 1+cur[j-1];
                int rep = 1+prev[j-1];
                cur[j] = min(del, min(ins, rep));
        }
    }
        prev = cur;
    }
        return prev[m];
}