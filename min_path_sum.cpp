#include <bits/stdc++.h>
//Memoization
int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>> dp){
        if(i==0 && j==0)
            return grid[i][j];
        if(dp[i][j] != -1)
            return dp[i][j];
        int up=INT_MAX, left = INT_MAX;
        if(i>0) up = grid[i][j] + solve(grid, i-1, j, dp);
        if(j>0 ) left = grid[i][j] + solve(grid, i, j-1, dp);
        return dp[i][j] = min(up, left);
    }

int minSumPath(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    // Space Optimizied Tabulation
    vector<int> prev(n, 0), curr(n, 0);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
             if(i==0 && j==0)
                 curr[j] = grid[i][j];
             else{
                   int up=INT_MAX, left = INT_MAX;
                   if(i>0) up = grid[i][j] + prev[j];
                   if(j>0 ) left = grid[i][j] + curr[j-1];
                   curr[j] = min(up, left);
             }
          }
          prev = curr;
      }
        return prev[n-1];
}