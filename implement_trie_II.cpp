#include<bits/stdc++.h>

class Node{
    Node* links[26];
    int cntprefix = 0;
    int endwith = 0;
    
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
    int getEnd(){
        return endwith;
    }
    int getPrefix(){
        return cntprefix;
    }
    void deleteEnd(){
        endwith--;
    }
    void reducePrefix(){
        cntprefix--;
    }
    void increasePrefix(){
        cntprefix++;
    }
    void setEnd(){
        endwith++;
    }
};

class Trie{
    Node* root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i]))
                node->put(word[i], new Node());
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->setEnd();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i]))
                return 0;
            node = node->get(word[i]);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i]))
                return 0;
            node = node->get(word[i]);
        }
        return node->getPrefix();
    }

    void erase(string &word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i]))
                return;
            node = node->get(word[i]);
            node->reducePrefix();
        }
        node->deleteEnd();
    }
};
