int longestSubSeg(vector<int> &arr , int n, int k){
    int ans = 0;
    int zero_count = 0, i = 0;
    for(int j=0; j<n; j++){
        if(arr[j] == 0)
            zero_count++;
        while(zero_count>k){
            if(arr[i] == 0)
                zero_count--;
            i++;
        }
        ans=max(ans, j-i+1);
    }
    return ans;
}
