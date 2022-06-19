int uniqueElement(vector<int> arr, int n)
{
	// Write your code here
    int a = arr[0];
    for(int i=1; i<n; i++){
        a = a^arr[i];
    }
    return a;
}
