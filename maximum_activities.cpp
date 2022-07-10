#include<bits/stdc++.h>
struct activities{
    public:
    int start;
    int end;
};

bool static compare(struct activities a, struct activities b){
    return a.end<b.end;
}

int maximumActivities(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n = start.size();
    struct activities act[n];
    for(int i=0; i<n; i++){
        act[i].start = start[i];
        act[i].end = end[i];
    }
    sort(act, act+n, compare);
    int ans = 1;
    int limit = act[0].end;
    for(int i=1; i<n; i++){
        if(act[i].start>=limit){
            limit=act[i].end;
            ans++;
        }
    }
    return ans;
}