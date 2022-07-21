void computeLps(string &p, vector<int> &lps, int m){
    int i=1, len=0;
    lps[0] = 0;
    while(i<m){
        if(p[i] == p[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len!=0)
                len = lps[len-1];
            else
                i++;
        }
    }
}

bool findPattern(string p, string s)
{
    int i=0, j=0;
    int m=p.size();
    int n=s.size();
    vector<int> lps(m, 0);
    computeLps(p, lps, m);
    while(i<n){
        if(p[j] == s[i]){
            i++;
            j++;
        }
        if(j==m)
            return true;
        else if(i<n && p[j]!=s[i]){
            if(j!=0)
                j = lps[j-1];
            else
                i++;
        }
    }
    return false;
}