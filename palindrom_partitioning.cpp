bool isPalindrom(string &s, int i, int j){
    while(i<=j){
        if(s[i]!=s[j])
            return false;
        i++;
        j--;
    }
}

void solve(string &s, vector<vector<string>> &ans, vector<string> path, int ind){
    if(ind == s.size()){
        ans.push_back(path);
        return;
    }
    for(int i=ind; i<s.size(); i++){
        if(isPalindrom(s, ind, i)){
            path.push_back(s.substr(ind, i-ind+1));
            solve(s, ans, path, i+1);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s) 
{
    vector<vector<string>> ans;
    vector<string> path;
    solve(s, ans, path, 0);
    return ans;
}