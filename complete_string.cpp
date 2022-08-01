#include<bits/stdc++.h>
class Node{
    Node* links[26];
    bool flag = false;
    public:
    bool containsKey(char ch){
        return (links[ch-'a'] != NULL);
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool checkallprefix(string word){
        Node* node = root;
        bool flag = true;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i]))
                return false;
            else{
                node = node->get(word[i]);
                flag = flag & node->isEnd();
            }
        }
        return flag;
    }
};
string completeString(int n, vector<string> &a){
    Trie* t = new Trie();
    string longest = "";
    for(auto it: a){
        t->insert(it);
    }
    for(int i=0; i<n; i++){
        if(t->checkallprefix(a[i])){
            if(a[i].length() > longest.length())
                longest = a[i];
            else if(a[i].length() == longest.length() && a[i]<longest)
                longest = a[i];
        }
    }
    if(longest == "")
        return "None";
    return longest;
}