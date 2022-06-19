#include<queue>
int signum(int a, int b){
	if(a>b)
		return 1;
	else if(a<b)
		return -1;
	else
		return 0;
}

void callMedian(int element, priority_queue<int, vector<int>, greater<int>> &mini,
			   priority_queue<int> &maxi, int &median){
	switch(signum(maxi.size(), mini.size())){
		case 0: if(element > median){
			mini.push(element);
			median = mini.top();
		}
			else{
				maxi.push(element);
				median = maxi.top();
			}
			break;
		case 1: if(element > median){
			mini.push(element);
			median = (maxi.top()+mini.top())/2;
		}
			else{
				mini.push(maxi.top());
				maxi.pop();
				maxi.push(element);
				median = (maxi.top()+mini.top())/2;
			}
			break;
		case -1: if(element > median){
			maxi.push(mini.top());
			mini.pop();
			mini.push(element);
			median = (maxi.top()+mini.top())/2;
		}
			else{
				maxi.push(element);
				median = (maxi.top()+mini.top())/2;
			}
			break;
	}
}

vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	priority_queue<int> maxheap;
	priority_queue<int, vector<int>, greater<int>> minheap;
	int median = -1;
	vector<int> ans;
	for(int i=0; i<n; i++){
		callMedian(arr[i], minheap, maxheap, median);
		ans.push_back(median);
	}
	return ans;
}
