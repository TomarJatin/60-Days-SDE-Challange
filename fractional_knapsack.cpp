#include<bits/stdc++.h>
bool static compare(pair<int, int> a, pair<int, int> b){
    return ((double)a.second/(double)a.first) > ((double)b.second/(double)b.first);
}

double maximumValue (vector<pair<int, int>>& arr, int n, int W)
{
    sort(arr.begin(), arr.end(), compare);

      int curWeight = 0;
      double finalvalue = 0.0;

      for (int i = 0; i < n; i++) {

         if (curWeight + arr[i].first <= W) {
            curWeight += arr[i].first;
            finalvalue += arr[i].second;
         } else {
            int remain = W - curWeight;
            finalvalue += (arr[i].second / (double) arr[i].first) * (double) remain;
            break;
         }
      }

      return finalvalue;
}