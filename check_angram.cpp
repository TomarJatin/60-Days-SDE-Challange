#include<bits/stdc++.h>
bool areAnagram(string &str1, string &str2){
    if(str1.size() != str2.size())
        return false;
    int n = str1.size();
    vector<int> s1(256, 0), s2(256, 0);
    for(int i=0; i<n; i++){
        s1[str1[i]]++;
        s2[str2[i]]++;
    }
    for(int i=0; i<256; i++){
        if(s1[i] != s2[i])
            return false;
    }
    return true;
}
