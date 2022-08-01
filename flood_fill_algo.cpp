#include<bits/stdc++.h>
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    int m = image.size(), n = image[0].size();
    int color = image[x][y];
    if(color == newColor)
        return image;
    queue<pair<int, int>> q;
    image[x][y] = newColor;
    q.push({x, y});
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    while(!q.empty()){
        int xi = q.front().first;
        int yi = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
           int nx = xi+dx[i], ny = yi+dy[i];
           if((nx>=0 && nx<m) && (ny>=0 && ny<n) && image[nx][ny] ==color){
               image[nx][ny] = newColor;
               q.push({nx, ny});
           }
        }
    }
    return image;
}