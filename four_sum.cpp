#include <bits/stdc++.h> 
string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    string ans = "No";
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int high = n-1;
            int low  = j+1;
            while(low<=high){
                int sum = arr[i]+arr[j]+arr[low]+arr[high];
                if(sum == target){
                    ans = "Yes";
                    return ans;
                }
                else if(sum > target)
                    high--;
                else
                    low++;
            }
        }
    }
    return ans;
}
