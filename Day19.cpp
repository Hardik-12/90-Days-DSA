#include <bits/stdc++.h>
using namespace std;


// Heap data structure
// 1. Used for implementing priority queues
// 2. Used in different standard algorithms like dijkstras,prims and huffman coding
// 3. Used for implementing heap sort
// 4. It is of 2 types:- min heap and max heap 
//     In min heap lowest numbered item is assigned highest priority->Every node has value smaller than its descendants
//     In max heap highest numbered item is assigned highest priority->Every node has value larger than its descendants
// 5. Binary heap is a complete binary tree->All levels are completely filled except possibly the last which is filled from left to right
// 6. The left child of a node can be found out by 2*i + 1 and right child can be found out by 2*i + 2 and parent of a node can be found out by (i-1)/2

// Maximum no of nodes of a complete binary tree at height h = ceil(n / 2^(h+1))

struct MinHeap{
	int *arr;
	int cap;
	int size;

	MinHeap(int y){
		cap = y;
		size = 6;
		arr = new int[y];
	}

	// Returns left child of a node
	int left(int i){
		return 2*i + 1;
	}

	// Returns right child of a node
	int right(int i){
		return 2*i + 2;
	}

	// Return parent of a node
	int parent(int i){
		return (i-1)/2;
	}

	// Inserting in a min-heap
	void insert(int x){
		if(size == cap){
			return;
		}
		arr[size] = x;
		int j = size;
		while(arr[parent(j)]>arr[j] && j!=0){
			swap(arr[parent(j)],arr[j]);
			j = parent(j);
		}
		size++;
	}

	// If root is violating the min-heap property
	// It can be used when root is disturbed and subtrees are heaps
	void heapify(int idx,int n){
		int i = idx;
		while(i<size){
			int left = 2*i + 1;
			int right = 2*i + 2;
			if((left>=n || right>=n) || 
				(arr[i]>arr[left] && arr[i]>arr[right])){
				break;
			}
			int curr = min(arr[left],arr[right]);
			if(curr == arr[left]){
				swap(arr[i],arr[left]);
				i = 2*i + 1;
			}else{
				swap(arr[i],arr[right]);
				i = 2*i + 2;
			}
		}
	}

	// Extracting minimum from a min-heap
	int extract_min(){
		if(size<=0){
			return INT_MIN;
		}
		if(size == 1){
			return arr[0];
		}
		swap(arr[0],arr[size-1]);
		heapify(0);
	}

    // Decrease key in min-heap
	void decrease_key(int idx,int val){
        // Making that index value as val and then check for heap property
		arr[idx] = val;
		int j = idx;
		while(arr[parent(j)]>arr[j] && parent(j)>=0){
			swap(arr[parent(j)], arr[j]);
			j = parent(j);
		}
	}

	// Delete a key from min heap
	void delete_ele(int idx){
		// Decrease key operation
		arr[idx] = INT_MIN;
		int j = idx;
		while(arr[parent(j)]>arr[j] && parent(j)>=0){
			swap(arr[parent(j)], arr[j]);
			j = parent(j);
		}
		// Extract minimum operation
		extract_min();
		size--;
	}

	// Build heap operation
	void build_heap(){
		// parent = (i-1)/2
		// Therefore, parent of last leaf = ((size-1) - 1)/2
		for(int j=(size-2)/2;j>=0;j--){
			heapify(j);
		}
	}
};

int main(){
	MinHeap obj(12);
	obj.arr[0] = 10;
	obj.arr[1] = 5;
	obj.arr[2] = 20;
	obj.arr[3] = 2;
	obj.arr[4] = 4;
	obj.arr[5] = 8;
	int idx = 3;
	int val = 5;
	obj.decrease_key(idx,val);
	for(int j=0;j<obj.size;j++){
		cout << obj.arr[j] << " ";
	}
	cout << "\n";
	obj.delete_ele(idx);
	for(int j=0;j<obj.size;j++){
		cout << obj.arr[j] << " ";
	}
	cout << "\n";
	obj.build_heap();
	for(int j=0;j<obj.size;j++){
		cout << obj.arr[j] << " ";
	}
	cout << "\n";
}

int main(){
	int n = 8;
	int arr[n] = {10,9,7,8,4,70,50,60};
	int k = 4;
	priority_queue<int,vector<int>,greater<int>> pq;
    // Every element in sorted order can be between i-k or i+k range
	for(int i=0;i<=k;i++){
		pq.push(arr[i]);
	}

	int idx = 0;
	for(int j=k+1;j<n;j++){
		arr[idx++] = pq.top();
		pq.pop();
		pq.push(arr[j]);
	}
	while(!pq.empty()){
		arr[idx++] = pq.top();
		pq.pop();
	}
	for(int i=0;i<n;i++){
		cout << arr[i] << " ";
	}
	cout << "\n";
}