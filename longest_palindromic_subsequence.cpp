string expand(int left, int right, string &str){
    int n = str.size();
    while(left>=0 && right<n){
        if(str[left] != str[right])
            break;
        left--;
        right++;
    }
    return str.substr(left+1, right-left-1);
}

string longestPalinSubstring(string str)
{
    int n  = str.length();
    string longest;
    for(int i=0; i<n; i++){
        string odd = expand(i, i, str);
        if(odd.size()>longest.size())
            longest = odd;
    }
    for(int i=0; i<n; i++){
        string even = expand(i, i+1, str);
        if(even.size()>longest.size())
            longest = even;
    }
    return longest;
}