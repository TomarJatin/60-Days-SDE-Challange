#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int n = arr.size();
    unordered_map<int, int> vis;
    int xr = 0, count = 0;
    for(int i=0; i<n; i++){
        xr ^= arr[i];
        if(xr == x)
            count++;
        int y = xr^x;
        if(vis.find(y) != vis.end())
            count+=vis[y];
        vis[xr]++;
    }
    return count;
}