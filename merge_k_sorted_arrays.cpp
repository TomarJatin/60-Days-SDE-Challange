#include<queue>
class node{
	public:
	int data;
	int i;
	int j;
	
	node(int data, int a, int b){
		this->data = data;
		i = a;
		j = b;
	}
};

class compare{
	public:
	bool operator()(node* a, node* b){
		return a->data > b->data;
	}
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
	priority_queue<node*, vector<node*>, compare> minHeap;
	for(int i=0; i<k; i++){
		node* temp = new node(kArrays[i][0], i, 0);
		minHeap.push(temp);
	}
	vector<int> ans;
	
	while(! minHeap.empty()){
		node* top = minHeap.top();
		ans.push_back(top->data);
		minHeap.pop();
		
		int i = top->i;
		int j = top->j;
		
		if(j+1<kArrays[i].size()){
			node* next = new node(kArrays[i][j+1], i, j+1);
			minHeap.push(next);
		}
	}
	return ans;
}
