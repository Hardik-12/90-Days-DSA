#include <bits/stdc++.h>
using namespace std;


int main(){
    //  Buy maximum items with given sum
    int n = 5;
	int arr[n] = {1,12,5,111,200};
	int sum = 10;


	priority_queue<int,vector<int>,greater<int>> pq;

	int check = 0;
	int no_of_items = 0;

	for(int i=0;i<n;i++){
		pq.push(arr[i]);
	}
	while(!pq.empty()){
		check+= pq.top();
		if(check>sum){
			break;
		}
		no_of_items++;
		pq.pop();
	}
	cout << no_of_items << "\n";
}

// Heap sort
// ----------

// 1. Build a max heap or min heap as per sorting criteria (ascending or descending order)
// 2. Repeatedly swap root with last node,reduce heap size by one and again heapify

// Heapify the heap
void heapify(vector<int> &arr,int idx,int n){
	int i = idx;
	while(i<n){
		int left = 2*i + 1;
		int right = 2*i + 2;
		if((left>=n || right>=n) || 
			(arr[i]>arr[left] && arr[i]>arr[right])){
			break;
		}

		int curr = max(arr[left],arr[right]);
		
		if(curr == arr[left]){
			swap(arr[i],arr[left]);
			i = 2*i + 1;	
		}else{
			swap(arr[i],arr[right]);
			i = 2*i + 2;
		}
	}
}

// Builds the max heap from array
void build_max_heap(vector<int> &arr,int n){
	int bottom_most_internal_node = (n-2)/2;
	for(int j=bottom_most_internal_node;j>=0;j--){
		heapify(arr,j,n);
	}
}

// Main function which builds a max heap and sorts the array
void heap_sort(vector<int> &arr,int n){
	build_max_heap(arr,n);
	for(int i=0;i<n;i++){
		cout << arr[i] << " ";
	}
	for(int i=n-1;i>=1;i--){
		swap(arr[0],arr[i]);
		heapify(arr,0,i);
	}
}

int main(){
	int n = 5;
	vector<int> arr = {10,15,50,4,20};
	heap_sort(arr,n);
	cout << "\n";
	for(int i=0;i<n;i++){
		cout << arr[i] << " ";
	}
}