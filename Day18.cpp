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


#include <bits/stdc++.h>
#define ll long long
#define vp vector<pair<int,int>>
#define vii vector<int>
#define vil vector<long long>
#define pii pair<int,int>
#define pb push_back
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repi(i,b,a) for(int i=b;i>=0;i--)
#define sum(arr) accumulate(arr.begin(),arr.end(),0)
#define mod 1000000007


using namespace std;


// Binary heap with array implementation
struct MinHeap{
	int *arr;
	int cap;
	int size;

	MinHeap(int y){
		cap = y;
		size = 10;
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
	void heapify(){
		int i = 0;
		while(i<size){
			int left = 2*i + 1;
			int right = 2*i + 2;
			int curr = min(arr[left],arr[right]);
			if(arr[i]<arr[left] && arr[i]<arr[right]){
				break;
			}
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
		int minn = arr[0];
		int i = 0;
		while(i<size){
			int left = 2*i + 1;
			int right = 2*i + 2;
			int curr = min(arr[left],arr[right]);
			if(left >= size || right >= size){
				break;
			}
			if(curr == arr[left]){
				arr[i] = arr[left];
				i = 2*i + 1;
			}else{
				arr[i] = arr[right];
				i = 2*i + 2;
			}
		}
		arr[size-2] = arr[size-1];
		size--;
		return minn;
	}
};

int main(){
	MinHeap obj(12);
	obj.arr[0] = 40;
	obj.arr[1] = 20;
	obj.arr[2] = 30;
	obj.arr[3] = 35;
	obj.arr[4] = 25;
	obj.arr[5] = 80;
	obj.arr[6] = 32;
	obj.arr[7] = 100;
	obj.arr[8] = 70;
	obj.arr[9] = 60;
	obj.heapify();
	for(int i=0;i<obj.size;i++){
		cout << obj.arr[i] << " ";
	}
	cout << "\n";
	cout << obj.extract_min() << "\n";
	for(int i=0;i<obj.size;i++){
		cout << obj.arr[i] << " ";
	}
	cout << "\n";
}

int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
    int row = INT_MAX;
    int res = 0;
    for(int i=0;i<n;i++){
        vector<int> arr_i = arr[i];
        int l = 0;
        int h = m-1;
        int cnt_1s = 0;
        while(l<=h){
            int mid = (l + h)/2;
            if(arr_i[mid] == 1){
                h = mid-1;
            }else if(arr_i[mid] == 0){
                l = mid+1;
            }
        }
        if(m-l > 0){
            cnt_1s+= (m-l);
        }
        
        if(cnt_1s > res){
            res = cnt_1s;
            row = i;
        }
    }
    if(row == INT_MAX){
        row = -1;
    }
    return row;
    
}

// Spirally traverse a matrix
vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
{
    // code here 
    vector<int> ans;
    int rs = 0;
    int re = r-1;
    int cs = 0;
    int ce = c-1;
    while(rs<=re && cs<=ce){
        for(int i=cs;i<=ce;i++){
            ans.push_back(matrix[rs][i]);
        }
        rs++;
        
        for(int j=rs;j<=re;j++){
            if(rs>re || cs>ce){
                break;
            }
            ans.push_back(matrix[j][ce]);
        }
        ce--;
        
        for(int k=ce;k>=cs;k--){
            if(rs>re || cs>ce){
                break;
            }
            ans.push_back(matrix[re][k]);
        }
        re--;
        
        for(int l=re;l>=rs;l--){
            if(rs>re || cs>ce){
                break;
            }
            ans.push_back(matrix[l][cs]);
        }
        cs++;
        
    }
    return ans;
}