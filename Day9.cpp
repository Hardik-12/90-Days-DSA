#include <bits/stdc++.h>
using namespace std;


// Stock span problem
// ----------------------
// span is defined as the no of consecutive days including the current
// day in which prices of stock are less than or equal to current day prices.


// In stock span problem we need to store useful indices so that
// we can decide th span for next element 

// The current element should be compared with its prevoius element 
// first and then previous greater of it and so on 

// So this is LIFO order and thats why we use stack data structure

int main(){
	int n = 6;
	int arr[n] = {30,20,25,28,27,29};
	stack<int> st;
	st.push(0);
	cout << 1 << " ";
	for(int i=1;i<n;i++){
		int span = 1;
		while(!st.empty() && arr[st.top()]<=arr[i]){
			span++;
			st.pop();
		}
		int curr_sit = st.empty()?i+1:(i-st.top());
		cout << curr_sit << " ";
		st.push(i);
	}
}

// Previous Greater Element
int main(){
	int n = 6;
	int arr[n] = {30,20,25,28,27,29};
	stack<int> st;
	st.push(0);
	// Previous greater of 1st element is nothing
	cout << -1 << " ";
	for(int i=1;i<n;i++){
		int span = 1;
		// Popping out all useless element with respect to current
		// element
		while(!st.empty() && arr[st.top()]<=arr[i]){
			span++;
			st.pop();
		}
		int curr_sit = st.empty()?-1:arr[st.top()];
		cout << curr_sit << " ";
		st.push(i);
	}
}

// Next Greater Element
int main(){
	int n = 4;
	int arr[n] = {10,15,20,25};
	vector<int> ans;
	stack<int> st;
	st.push(n-1);
	ans.push_back(-1);
	for(int i=n-2;i>=0;i--){
		while(!st.empty() && arr[i]>=arr[st.top()]){
			st.pop();
		}
		int curr = st.empty()?-1:arr[st.top()];
		ans.push_back(curr);
		st.push(i);
	}
	reverse(ans.begin(), ans.end());
	for(auto x: ans){
		cout << x << " ";
	}
}

// Stack with getMin in O(1) time and O(n) space
struct stack_with_get_min{
	stack<int> st1;
	stack<int> st2;

	void pushElement(int x){
		if(st1.empty()){
			st2.push(x);
		}else{
			if(x<st2.top()){
				st2.push(x);
			}
		}
		st1.push(x);
	}

	int get_min(){
		int curr = st2.top();
		return curr;
	}

	int popElement(){
		if(!st1.empty()){
			int popped_element = st1.top();
			st1.pop();
			if(popped_element == st2.top()){
				st2.pop();
			}
			return popped_element;
		}
	}
};

int main(){
	stack_with_get_min obj;
	obj.pushElement(5);
	obj.pushElement(4);
	obj.pushElement(3);
	cout << obj.get_min() << "\n";
	cout << "Popped " << obj.popElement() << "\n";
	cout << obj.get_min() << "\n";
	obj.pushElement(2);
	cout << obj.get_min() << "\n";
}