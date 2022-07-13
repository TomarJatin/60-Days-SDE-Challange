bool isPresent(string &s, vector<string> &dict){
    for(string st: dict){
        if(st.compare(s) == 0)
            return true;
    }
    return false;
}

void solve(string &s, vector<string> &dictionary, string &path, vector<string> &ans, int ind){
    if(ind == s.size()){
        ans.push_back(path);
        return;
    }
    for(int i=ind; i<s.size(); i++){
        string word = s.substr(ind, i-ind+1);
        if(isPresent(word, dictionary)){
            string x = path;
            path+=word+" ";
            solve(s, dictionary, path, ans, i+1);
            path = x;
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    string path = "";
    vector<string> ans;
    solve(s, dictionary, path, ans, 0);
    return ans;
}