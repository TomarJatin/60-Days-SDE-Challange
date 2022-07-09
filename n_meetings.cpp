#include<bits/stdc++.h>
struct meet{
    int start;
    int end;
    int pos;
};

bool static compare(struct meet a, struct meet b){
    if(a.end < b.end) return true;
    else if (a.end>b.end) return false;
    else if(a.pos<b.pos) return true;
    return false;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    struct meet m[n];
    for(int i=0; i<n; i++)
        m[i].start = start[i], m[i].end = end[i], m[i].pos = i+1;
    
    sort(m, m+n, compare);
    
    vector<int> ans;
    int limit = m[0].end;
    ans.push_back(m[0].pos);
    
    for(int i=1; i<n; i++){
        if(m[i].start > limit){
            limit = m[i].end;
            ans.push_back(m[i].pos);
        }
    }
    return ans;
}