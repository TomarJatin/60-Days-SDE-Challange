int findMinimumCoins(int amount) 
{
    // Write your code here
    int n = 9;
    int arr[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int ans=0;
    for(int i=0; i<n; i++){
        if(amount>=arr[i]){
            ans+=amount/arr[i];
            amount=amount%arr[i];
        }
    }
    return ans;
}
