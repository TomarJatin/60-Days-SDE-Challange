#include <bits/stdc++.h>

using namespace std;

 

int dx[4] = {-1, 0, 0, 1};

int dy[4] = {0, -1, 1, 0};

 

void solve(vector<vector<int>> &maze, vector<vector<int>> &visited, int x, int y, int n, vector<vector<int>> &res)

{

    visited[x][y] = 1;

    if (x == n - 1 && y == n - 1)

    {

        int i, j;

        vector<int> temp;

        for (i = 0; i < n; i++)

        {

            for (j = 0; j < n; j++)

            {

                temp.push_back(visited[i][j]);

            }

        }

        res.push_back(temp);

        visited[x][y] = 0;

        return;

    }

    int i, row, col;

    for (i = 0; i < 4; i++)

    {

        row = x + dx[i], col = y + dy[i];

        if (row >= 0 && row < n && col >= 0 && col < n && visited[row][col] == 0 && maze[row][col] == 1)

        {

            solve(maze, visited, row, col, n, res);

        }

    }

    visited[x][y] = 0;

}

 

vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n)

{

    vector<vector<int>> visited(n, vector<int>(n, 0));

    vector<vector<int>> res;

    solve(maze, visited, 0, 0, n, res);

    return res;

}