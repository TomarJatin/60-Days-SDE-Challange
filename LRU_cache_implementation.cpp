#include<bits/stdc++.h>
class LRUCache
{
public:
    class node{
        public:
        int val, key;
        node* prev;
        node* next;
        
        node(int k, int v){
            val = v;
            key = k;
        }
    };
    int cap;
    unordered_map<int, node*> m;
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void insertNode(node* newnode){
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deleteNode(node* todelete){
        node* delprev = todelete->prev;
        node* delnext = todelete->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key_)
    {
        if(m.find(key_) != m.end()){
            node* rnode = m[key_];
            int ans = rnode->val;
            m.erase(key_);
            deleteNode(rnode);
            insertNode(rnode);
            m[key_] = head->next;
            return ans;
        }
        return -1;
    }

    void put(int key_, int value)
    {
        if(m.find(key_) != m.end()){
            node* todelete = m[key_];
            m.erase(key_);
            deleteNode(todelete);
        }
        if(cap == m.size()){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        insertNode(new node(key_, value));
        m[key_] = head->next;
    }
};
