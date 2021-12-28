#include <bits/stdc++.h>
using namespace std;

// Stack using array
struct stack_using_array{
	int cap;
	int *arr;
	int size;
	int top;

	stack_using_array(int x){
		cap = x;
		arr = new int[cap];
		top = 0;
		size = 0;
	}

	bool is_empty(){
		if(size == 0){
			return  true;
		}
		return false;
	}

	int get_size(){
		return size;
	}

	int get_top(){
		return arr[top];
	}

	void push(int y){
		if(size < cap){
			top++;
			arr[top] = y;
			size++;
		}
	}

	int pop(){
		if(is_empty() == false){
			int curr = arr[top];
			top--;
			size--;
			return curr;
		}
	}

};


// Stack using Linked List

// Initially head = NULL
// We are inserting every node before head and making that node as head

struct Node{
	int data;
	Node* next;

	Node(int x){
		data = x;
		next = NULL;
	}
};

struct stack_using_LL{
	int size;
	Node* head;

	stack_using_LL(){
		size = 0;
		head = NULL;
	}

	bool is_empty(){
		if(size == 0){
			return true;
		}
		return false;
	}

	void pushNode(int x){
		Node* temp = new Node(x);
		temp->next = head;
		head = temp;
		size++;
	}

	int popNode(){
		if(head == NULL){
			return 0;
		}
		size--;
		int res = head->data;
		Node* store = head;
		head = head->next;
		delete(store);
		return res;
	}

	int get_size(){
		return size;
	}
};



int main(){
	stack_using_array obj(8);
	obj.push(3);
	obj.push(4);
	obj.push(6);
	obj.push(7);
	cout << obj.pop() << "\n";
	if(obj.is_empty()){
		cout << "Yes" << "\n";
	}else{
		cout << "No" << "\n";
	}
	cout << obj.get_top() << "\n";
	cout << obj.get_size() << "\n";
	obj.push(10);
	obj.push(11);
	cout << obj.pop() << "\n";
}

// Balanced Parenthesis
bool ispar(string x){
    if(x[0] == ')' || x[0] == '}' || x[0] == ']'){
        return false;
    }
    stack<char> st;
    for(int i=0;i<x.length();i++){
        // If current character is an opening bracket
        if(x[i] == '(' || x[i] == '{' || x[i] == '['){
            st.push(x[i]);
        }else{
            // If current character is a closing bracket
            while(!st.empty()){
                if((st.top() == '[' && x[i] == ']') || 
                (st.top() == '{' && x[i] == '}') || 
                (st.top() == '(' && x[i] == ')')){
                    st.pop();
                    break;
                }else{
                    return false;
                }
                
            }
        }
    }
    return (st.empty()?true:false);
}


// Implement 2 stacks in array
void twoStacks :: push1(int x)
{
    if(top1 == top2-1){
        return;
    }else{
        top1++;
        arr[top1] = x;
    }
}
   
//Function to push an integer into the stack2.
void twoStacks ::push2(int x)
{
    if(top1 == top2-1){
        return;
    }else{
        top2--;
        arr[top2] = x;
    }
}
   
//Function to remove an element from top of the stack1.
int twoStacks ::pop1()
{
    if(top1 > -1){
        int popped_element = arr[top1];
        top1--;
        return popped_element;
    }else{
        return -1;
    }
}

//Function to remove an element from top of the stack2.
int twoStacks :: pop2()
{
    if(top2 < size){
        int popped_element = arr[top2];
        top2++;
        return popped_element;
    }else{
        return -1;
    }
}
