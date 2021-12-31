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

// enqueue
// dequeue
// size
// getfront
// getrear
// isfull
// isempty


// Queue using array
struct queue_using_array{
	int *arr;
	int size_q;
	int cap;
	int front;

	queue_using_array(int x){
		cap = x;
		arr = new int[cap];
		front = 0;
		size_q = 0;
	}

	int get_rear(){
		return (front + size_q - 1)%cap;
	}

	void enqueue(int y){
		int rear = get_rear();
		rear = (rear+1)%cap;
		if(front == rear){
			return;
		}
		arr[rear] = y;
		size_q++;
	}

	void dequeue(){
		if(isEmpty()){
			return;
		}else{
			front = (front + 1)%cap;
		}
		size_q--;
	}

	int size(){
		return size_q;
	}

	int get_front(){
		return front;
	}

	bool isFull(){
		return (size_q == cap);
	}

	bool isEmpty(){
		return (size_q == 0);
	}
};

int main(){
	queue_using_array obj(5);
	obj.enqueue(2);
	obj.enqueue(5);
	obj.enqueue(7);
	obj.enqueue(9);
	obj.enqueue(10);
	obj.dequeue();
	obj.dequeue();
	obj.enqueue(17);
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	obj.dequeue();
	if(obj.isFull()){
		cout << "Yes" << "\n";
	}else{
		cout << "No" << "\n";
	}
	if(obj.isEmpty()){
		cout << "Yes" << "\n";
	}else{
		cout << "No" << "\n";
	}
	obj.enqueue(8);
	obj.enqueue(18);
	cout << obj.get_front() << "\n";
	cout << obj.get_rear() << "\n";
}

// Queue using linked list

struct Node{
	int data;
	Node* next;

	Node(int x){
		data = x;
		next = NULL;
	}
};

struct queue_using_LL{
	int size_q;
	Node* head;
	Node* tail;

	queue_using_LL(){
		size_q = 0;
		head = NULL;
		tail = NULL;
	}

	void enqueue(int y){
		Node* temp = new Node(y);
		if(head == NULL){
			head = temp;
			tail = temp;
		}else{
			tail->next = temp;
			tail = temp;
		}
		size_q++;
	}

	int dequeue(){
		if(head == NULL){
			return -1;
		}else{
			int dequed_element = head->data;
			Node* store = head->next;
			delete(head);
			head = store;
			return dequed_element;
		}
		size_q--;
	}

	int get_size(){
		return size_q;
	}

	bool isEmpty(){
		return (head == NULL);
	}

	int get_front(){
		int front_element = head->data;
		return front_element;
	}
	int get_rear(){
		int rear_element = tail->data;
		return rear_element;
	}
};

int main(){
	queue_using_LL obj;
	obj.enqueue(2);
	obj.enqueue(5);
	obj.enqueue(7);
	cout << obj.dequeue() << "\n";
	cout << obj.dequeue() << "\n";
	obj.enqueue(9);
	cout << obj.get_front() << "\n";
	cout << obj.get_rear() << "\n";
	if(obj.isEmpty()){
		cout << "Yes" << "\n";
	}else{
		cout << "No" << "\n";
	}
}


// Implement stack using queue

struct stack_using_queue{
	queue<int> q1;
	queue<int> q2;

	void pushEle(int x){
		while(!q1.empty()){
			int curr = q1.front();
			q1.pop();
			q2.push(curr);
		}

		q1.push(x);

		while(!q2.empty()){
			int curr = q2.front();
			q2.pop();
			q1.push(curr);
		}
	}

	int get_top(){
		return q1.front();
	}
	int popEle(){
		int curr = q1.front();
		q1.pop();
		return curr;
	}

};

int main(){
	stack_using_queue obj;
	obj.pushEle(2);
	obj.pushEle(5);
	obj.pushEle(7);
	obj.pushEle(9);
	cout << obj.popEle() << "\n";
	cout << obj.popEle() << "\n";
}