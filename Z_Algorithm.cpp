void getZArray(string &s, vector<int> &Z){
    int n= Z.size();
    int l, r, k, i;
    l = r = 0;
    for(int i=0; i<n; i++){
        if(i>r){
            r=l=i;
            while(r<n && s[r-l]==s[r])
                r++;
            Z[i] = r-l;
            r--;
        }
        else{
        k=i-l;
        if(Z[k]<r-i+1)
            Z[i] = Z[k];
        else{
            l=i;
            while(r<n && s[r-l]==s[r])
                r++;
            Z[i] = r-l;
            r--;
        }
    }
    }
}

int zAlgorithm(string s, string p, int n, int m)
{
	// Write your code here
    string cont = p+"$"+s;
    int l = cont.size();
    vector<int> Z(l, 0);
    getZArray(cont, Z);
    int count = 0;
    for(int i=0; i<l; i++){
        if(Z[i] == m)
            count++;
    }
    return count;
}