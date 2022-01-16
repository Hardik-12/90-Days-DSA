#include <bits/stdc++.h>
using namespace std;

//Function to merge K sorted linked list.
Node* merge(Node* l1,Node* l2){
    Node* dummy = new Node(-1);
    Node* new_node = dummy;
    while(l1 && l2){
        if(l1->data<=l2->data){
            new_node->next = l1;
            l1 = l1->next;
        }else{
            new_node->next = l2;
            l2 = l2->next;
        }
        new_node = new_node->next;
    }
    if(l1){
        new_node->next = l1;
        new_node = new_node->next;
    }else{
        new_node->next = l2;
        new_node = new_node->next;
    }
    return dummy->next;
}

Node * mergeKLists(Node *arr[], int K)
{
        // Your code here
    if(K==1){
        return arr[0];
    }
    Node* ans = merge(arr[0],arr[1]);
    for(int i=2;i<K;i++){
        ans = merge(ans,arr[i]);
    }
    return ans;
}

// Merge 2 binary max heaps

void heapify(vector<int> &ans,int idx,int merge_size){
    if(idx>=merge_size){
        return;
    }
    int i = idx;
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left<merge_size && ans[left]>ans[largest]){
        largest = left;
    }
    if(right<merge_size && ans[right]>ans[largest]){
        largest = right;
    }
    if(largest!=i){
        swap(ans[i],ans[largest]);
        heapify(ans,largest,merge_size);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    // your code here
    vector<int> ans(n+m);
    for(int i=0;i<n;i++){
        ans[i] = a[i];
    }
    for(int j=0;j<m;j++){
        ans[n+j] = b[j];
    }
    int merge_size = n+m;
    for(int j=(merge_size-2)/2;j>=0;j--){
        heapify(ans,j,merge_size);
    }
    return ans;
}