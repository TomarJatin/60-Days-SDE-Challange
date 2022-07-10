void solve(vector<int> &num, vector<int> &ans, int sum, int i){
    if(i>=num.size()){
    ans.push_back(sum);
        return;
    }
    solve(num, ans, sum, i+1);
    solve(num, ans, sum+num[i], i+1);
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    int n=num.size();
    solve(num, ans, 0, 0);
    sort(ans.begin(), ans.end());
    return ans;
}