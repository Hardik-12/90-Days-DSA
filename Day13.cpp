#include <bits/stdc++.h>
using namespace std;

// Generate numbers with given digits
vector<string> generate_no(int N)
{
	// Your code here
	vector<string> ans;
	queue<string> q;
	q.push("1");
	q.push("0");
	for(int i=0;i<=N;i++){
	    string curr = q.front();
	    q.pop();
	    if(curr != "0"){
	        ans.push_back(curr);
	        q.push(curr+"0");
	        q.push(curr+"1");
	    }
	    
	}
	return ans;
}

int main(){
    int N=10;
    vector<string> res = generate_no(N);
    for(auto x: res){
        cout << x << " ";
    }
}

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

struct find_middle_in_stack{
	Node* head;
	Node* mid;
	int size_LL;

	find_middle_in_stack(){
		head = NULL;
		mid = NULL;
		size_LL = 0;
	}

	void pushEle(int y){
		Node* temp = new Node(y);
		if(head == NULL){
			head = temp;
			mid = temp;
			size_LL++;
			return;
		}
		head->next = temp;
		temp->prev = head;
		head = head->next;
		if(size_LL&1){
			mid = mid->next;
		}
		size_LL++;
	}

	int popEle(){
		if(head == NULL){
			return -1;
		}else{
			head = head->prev;
			head->next = NULL;
			if((size_LL&1) == 0){
				mid = mid->prev;
			}
		}
		size_LL--;
	}

	int find_middle(){
		return mid->data;
	}
};


int main(){
	find_middle_in_stack obj;
	obj.pushEle(6);
	obj.pushEle(5);
	obj.pushEle(4);
	obj.pushEle(3);
	cout << obj.find_middle() << "\n";
	cout << obj.popEle() << "\n";
	cout << obj.find_middle() << "\n";
	obj.pushEle(2);
	obj.pushEle(1);
	obj.pushEle(10);
	obj.pushEle(11);
	obj.pushEle(12);
	cout << obj.find_middle() << "\n";
	cout << obj.popEle() << "\n";
	cout << obj.find_middle() << "\n";
}