#include<bits/stdc++.h>
int countelemets(vector<int> &row, int mid)
{
  int l = 0, h = row.size() - 1;
  while (l <= h)
  {
    int md = (l + h) >> 1;
    if (row[md] <= mid)
    {
      l = md + 1;
    }
    else
    {
      h = md - 1;
    }
  }
  return l;
}
int getMedian(vector<vector<int>> &matrix)
{
  int low = 1, high = 1e9;
  int n = matrix.size();
  int m = matrix[0].size();
  int goal = (n * m) / 2;
  while (low <= high)
  {
    int mid = (low + high) >> 1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
      count += countelemets(matrix[i], mid);
    }
    if (count <= goal)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low;
}