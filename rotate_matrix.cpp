#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int row=0, col=0, prev, cur;
    while(row<n && col<m){
        if(row+1==n || col+1==m)
            break;
        prev = mat[row+1][col];
        for(int j=col; j<m; j++){
            cur = mat[row][j];
            mat[row][j] = prev;
            prev = cur;
        }
        row++;
        for(int i=row; i<n; i++){
            cur = mat[i][m-1];
            mat[i][m-1] = prev;
            prev = cur;
        }
        m--;
        if(row<n)
        for(int j=m-1; j>=col; j--){
            cur = mat[n-1][j];
            mat[n-1][j] = prev;
            prev = cur;
        }
        n--;
        if(col<m)
        for(int i=n-1; i>=row; i--){
            cur = mat[i][col];
            mat[i][col] = prev;
            prev = cur;
        }
        col++;
    }
}