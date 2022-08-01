#include<bits/stdc++.h>
class Node{
    Node* links[2];
    public:
    bool containsKey(int ind){
        return (links[ind]!=NULL);
    }
    void put(int ind, Node* node){
        links[ind] = node;
    }
    Node* get(int ind){
        return links[ind];
    }
};

class Trie{
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node* node = root;
        for(int i=31; i>=0; i--){
            int bit = (num>>i) & 1;
            if(!node->containsKey(bit))
                node->put(bit, new Node());
            node = node->get(bit);
        }
    }
    
    int findMaxXor(int num){
        Node* node = root;
        int maxNum = 0;
        for(int i=31; i>=0; i--){
            int bit = (num>>i)&1;
            if(node->containsKey(!bit)){
                maxNum = maxNum | (1<<i);
                node = node->get(!bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries) {
    int q = queries.size();
    sort(arr.begin(), arr.end());
    vector<pair<int, pair<int, int>>> Q;
    for(int i=0; i<q; i++){
        Q.push_back({queries[i][1], {queries[i][0], i}});
    }
    sort(Q.begin(), Q.end());
    vector<int> ans(q, 0);
    int ind = 0;
    int n = arr.size();
    Trie trie;
    for(int i=0; i<q; i++){
        int ai = Q[i].first;
        int xi = Q[i].second.first;
        int qind = Q[i].second.second;
        while(ind<n && arr[ind]<=ai){
            trie.insert(arr[ind]);
            ind++;
        }
        if(ind == 0) ans[qind] = -1;
        else ans[qind] = trie.findMaxXor(xi);
    }
    return ans;
}