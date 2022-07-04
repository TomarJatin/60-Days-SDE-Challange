#include <bits/stdc++.h> 
int  merge(vector<int> &arr, int left, int mid, int right)
{
    int count=0, j=mid+1;
    for(int i=left; i<=mid; i++){
        while(j<=right && arr[i]> 2* arr[j])
            j++;
        count+= (j-(mid+1));
    }
    vector<int> temp;
    int i=left;
    j=mid+1;
    while(i<=mid && j<=right){
        if(arr[i]<arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }
    while(i<=mid)
        temp.push_back(arr[i++]);
    while(j<=right)
        temp.push_back(arr[j++]);
    
    for(int i=left; i<=right; i++){
        arr[i] = temp[i-left];
    }
    return count;
}

int merge_Sort(vector<int> &arr, int left, int right)
{
    int mid;
    int count = 0;
    if(right > left)
    {
        mid = (left + right)/2;

        count += merge_Sort(arr,left,mid);
        count += merge_Sort(arr,mid+1,right);

        count += merge(arr,left,mid,right);
    }
    return count;
}
int reversePairs(vector<int> &arr, int n){
	// Write your code here.
    return merge_Sort(arr, 0, n-1);
}