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

int maximumXor(vector<int> A)
{
    Trie* t = new Trie();
    int n = A.size();
    for(int i=0; i<n; i++){
        t->insert(A[i]);
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, t->findMaxXor(A[i]));
    }
    return ans;
}