int maximumProduct(vector<int> &arr, int n)
{
	int prod1 = arr[0], prod2 = arr[0];
    int ans = arr[0];
    for(int i=1; i<n; i++){
        int temp = max(arr[i], max(prod1*arr[i], prod2*arr[i]));
        prod2 = min(arr[i], min(prod1*arr[i], prod2*arr[i]));
        prod1 = temp;
        
        ans = max(ans, prod1);
    }
    return ans;
}
