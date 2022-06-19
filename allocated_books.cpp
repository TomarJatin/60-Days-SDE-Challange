
bool isPossible(vector<int> time, int m, int n, long long mid){
    int count =1;
    long long t =0;
    for(int i=0; i<m; i++){
        if(t+time[i]<=mid){
            t += time[i];
        }
        else{
            count++;
            if(count>n || time[i] > mid)
                return false;
            t = time[i];
        }
    }
    return true;
    
}
    

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
    long long totalTime = 0;
    for(int i=0; i<m; i++)
        totalTime+=time[i];
    long long start = 0, end = totalTime;
    long long ans=-1;
    while(start<=end){
        long long mid = (start+(end-start)/2);
        if(isPossible(time, m, n, mid)){
            ans = mid;
            end = mid -1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}