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


struct Node{
	int data;
	Node* next;
	Node* prev;

	Node(int x){
		data = x;
		next = NULL;
		prev = NULL;
	}
};

// Rotate a Linked List by n nodes

Node* rotate_by_n_nodes(Node* head,int n){
	if(head == NULL || head->next == NULL){
		return head;
	}

	Node* curr = head;
	while(curr->next){
		curr = curr->next;
	}

	Node* temp = head;
	Node* store = NULL;
	for(int i=0;i<n;i++){
		if(i == n-1){
			store = temp;
		}
		temp = temp->next;
	}
	store->next = NULL;
	temp->prev = NULL;

	curr->next = head;
	head->prev = curr;

	return temp;
}

int main(){
	int n = 5;
	Node* head = new Node(1);
	Node* node1 = new Node(2);
	Node* node2 = new Node(3);
	Node* node3 = new Node(4);
	Node* node4 = new Node(5);
	Node* node5 = new Node(6);

	head->next = node1;
	head->prev = NULL;

	node1->next = node2;
	node1->prev = head;

	node2->next = node3;
	node2->prev = node1;

	node3->next = node4;
	node3->prev = node2;

	node4->next = node5;
	node4->prev = node3;

	node5->next = NULL;
	node5->prev = node4;

	Node* ans = rotate_by_n_nodes(head,n);

	while(ans){
		cout << ans->data << " ";
		ans = ans->next;
	}
}

// Reverse a linked list in groups of given size
struct node *reverse (struct node *head, int k){ 
    node* store;
    node* prev = NULL;
    int cnt = 0;
    node* curr = head;
    while(curr && cnt<k){
        store = curr->next;
        curr->next = prev;
        prev = curr;
        curr = store;
        cnt++;
    }
    if(store){
        head->next = reverse(store,k);
    }
    return prev;
}

// Reverse first k elements of queue

queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    int y = q.size();
    stack<int> stk;
    for(int i=0;i<k;i++){
        stk.push(q.front());
        q.pop();
    }
    for(int i=0;i<k;i++){
        q.push(stk.top());
        stk.pop();
    }
    int rem_elements = y-k;
    for(int i=0;i<rem_elements;i++){
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}