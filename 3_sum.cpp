#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i=0; i<n-2; i++){
        if(i==0 || (i>0 && arr[i] != arr[i-1])){
            int low = i+1, high = n-1;
            while(low<high){
                int sum = arr[low]+arr[high]+arr[i];
                if(sum == K){
                    vector<int> a(3);
                    a[0] = arr[i];
                    a[1] = arr[low];
                    a[2] = arr[high];
                    ans.push_back(a);
                    while(low<high  && arr[low] == arr[low+1])
                        low++;
                    while(low<high && arr[high] == arr[high-1])
                        high--;
                    low++; 
                    high--;
                }
                else if(sum < K)
                    low++;
                else
                    high--;
            }
        }
    }
    return ans;
}