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

// Largest rectangular area in a histogram
// Naive approach

int main(){
	int n = 7;
	int arr[] = {6,2,5,4,1,5,6};
	
	int res = 0;
	for(int i=0;i<n;i++){
		int cnt = 1;
		for(int j=i;j>=0;j--){
            // Traverse on the left until you find a smaller bar
			if(arr[j]>=arr[i]){
				res = max(res,arr[i]*cnt);
				cnt++;
			}else{
				break;
			}
		}

		for(int k=i+1;k<n;k++){
            // Traverse on the right until you find a smaller bar
			if(arr[k]>=arr[i]){
				res = max(res,arr[i]*cnt);
				cnt++;
			}else{
				break;
			}
		}
	}
	cout << res << "\n";
}

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

// Largest rectangular area in a histogram

// Storing the index of previous smaller of every element
void previous_smaller(vector<int> arr,vector<int> &res,int n){
	stack<int> st;
	st.push(0);
	res.push_back(-1);
	for(int i=1;i<n;i++){
		while(!st.empty() && arr[st.top()]>=arr[i]){
			st.pop();
		}
		int curr = st.empty()?-1:st.top();
		res.push_back(curr);
		st.push(i);
	}
}

// Storing the index of next smaller of every element
void next_smaller(vector<int> arr,vector<int> &res2,int n){
	stack<int> st;
	st.push(n-1);
	res2.push_back(n);
	for(int i=n-2;i>=0;i--){
		while(!st.empty() && arr[st.top()]>=arr[i]){
			st.pop();
		}
		int curr = st.empty()?-1:st.top();
		if(curr == -1){
			res2.push_back(n);
		}else{
			res2.push_back(curr);
		}
		st.push(i);
	}
	reverse(res2.begin(),res2.end());
}

int main(){
	int n = 7;
	vector<int> arr = {6,2,5,4,1,5,6};
	vector<int> res;
	vector<int> res2;
	previous_smaller(arr,res,n);
	next_smaller(arr,res2,n);
	int maxx = 0;
	for(int i=0;i<n;i++){
		int curr = arr[i];
		curr+= (i-res[i]-1)*arr[i];
		curr+= (res2[i]-i-1)*arr[i];
		maxx = max(maxx,curr);
	}
	cout << maxx << "\n";
}

// Delete nodes having greater value on right

Node* reverse_list(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    while(curr){
        Node* next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }
    return prev;
}

Node *compute(Node *head)
{
    // your code goes here
    head = reverse_list(head);
    int curr_element = head->data;
    Node* dummy = new Node(-1);
    Node* store = dummy;
    Node* curr_node = head;
    store->next = curr_node;
    store = curr_node;
    curr_node = curr_node->next;
    while(curr_node){
        if(curr_node->data>=curr_element){
            store->next = curr_node;
            store = curr_node;
            curr_element = curr_node->data;
        }
        curr_node = curr_node->next;
    }
    store->next = NULL;
    return reverse_list(dummy->next);
}
    