#include<bits/stdc++.h>
bool comparator(vector<int> j1, vector<int> j2){
    return j1[1] > j2[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), comparator);
    int max_deadline = jobs[0][0];
    for(int i=1; i<n; i++)
        max_deadline = max(max_deadline, jobs[i][0]);
    vector<int> deadline(max_deadline+1, -1);
    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=jobs[i][0]; j>0; j--){
            if(deadline[j] == -1){
                deadline[j] = i;
                ans+=jobs[i][1];
                break;
            }
        }
    }
    return ans;
}
