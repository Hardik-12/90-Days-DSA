#include <bits/stdc++.h>
using namespace std;

// Get Nth node from last
int getNthFromLast(Node *head, int n)
{
    if(head == NULL){
        return -1;
    }
    Node* slow = head;
    Node* fast = head;
    for(int i=0;i<n;i++){
        fast = fast->next;
        // Checking if length of linked list and n are same
        if(fast == NULL && i < n-1){
            return -1;
        }
    }
    
    while(fast){
        slow = slow->next;
        fast = fast->next;
    }
    // This will now point to nth node from last
    return slow->data;
}

// Segregate even and odd nodes in LL

Node* divide(int N, Node *head){
        // code here
    Node* es = NULL;
    Node* ee = NULL;
    Node* os = NULL;
    Node* oe = NULL;
    Node* curr = head;
    while(curr){
        if((curr->data&1) == 0){
            if(es == NULL){
                es = curr;
                ee = curr;
            }else{
                ee->next = curr;
                ee = curr;
            }
        }else{
            if(os == NULL){
                os = curr;
                oe = curr;
            }else{
                oe->next = curr;
                oe = curr;
            }
        }
        curr = curr->next;
    }
    if(ee){
        ee->next = os;
    }
    if(oe){
        oe->next = NULL;
    }
    if(es){
        return es;
    }else{
        return os;
    }
}

// Multiply two Linked List

struct Node{
	int data;
	Node* next;

	Node(int x){
		data = x;
		next = NULL;
	}
};

Node* reverse_list(Node* head){
	Node* curr = head;
	Node* prev = NULL;
	while(curr){
		Node* store = curr->next;
		curr->next = prev;
		prev = curr;
		curr = store;
	}
	return prev;
}

void add_two_LL(Node* head,Node* org_ans){
	Node* c1 = head;
	Node* c2 = org_ans;

	int carry = 0;
	while(c1 || carry){
		int sum = 0;
		sum = carry + (c1 != NULL ? c1->data : 0) + 
		(c2->next != NULL ? c2->next->data : 0);
		int digit_req = sum%10;
		carry = sum/10;
		if(c2->next){
			c2->next->data = digit_req;
		}else{
			c2->next = new Node(digit_req);
		}
		
		if(c1){
			c1 = c1->next;
		}
		c2 = c2->next;
	}
}

Node* multiply_with_digit(Node* head,int val){
	Node* dummy = new Node(-1);
	Node* new_LL = dummy;
	Node* curr = head;
	int carry = 0;
	while(curr || carry){
		int sum = 0;
		sum = carry + (curr != NULL ? curr->data : 0)*val;
		int digit_req = sum%10;
		carry = sum/10;
		new_LL->next = new Node(digit_req);
		if(curr){
			curr = curr->next;
		}
		new_LL = new_LL->next;
	}
	return dummy->next;
}

Node* multiply_two_LL(Node* l1,Node* l2){
	l1 = reverse_list(l1);
	l2 = reverse_list(l2);

	Node* dummy_ans = new Node(-1);
	Node* org_ans = dummy_ans;

	Node* l2_itr = l2;

	while(l2_itr){
		Node* prod = multiply_with_digit(l1,l2_itr->data);
		l2_itr = l2_itr->next;
		add_two_LL(prod,org_ans);
		org_ans = org_ans->next;
	}
	return reverse_list(dummy_ans->next);
}

int main(){
	Node* l1 = new Node(1);
	l1->next = new Node(2);
	l1->next->next = new Node(4);
	l1->next->next->next = new Node(2);
	l1->next->next->next->next = NULL;

	Node* l2 = new Node(2);
	l2->next = new Node(3);
	l2->next->next = NULL;

	Node* ans = multiply_two_LL(l1,l2);
	while(ans){
		cout << ans->data << " ";
		ans = ans->next;
	}
}

// Merge K sorted Linked Lists

Node* merge(Node* head1, Node* head2){
    Node* dummy = new Node(-1);
    Node* new_LL = dummy;
    Node* curr1 = head1;
    Node* curr2 = head2;
    while(curr1 && curr2){
        if(curr1->data <= curr2->data){
            new_LL->next = curr1;
            if(curr1){
                curr1 = curr1->next;
            }
            new_LL = new_LL->next;
        }else if(curr2->data < curr1->data){
            new_LL->next = curr2;
            if(curr2){
                curr2 = curr2->next;
            }
            new_LL = new_LL->next;
        }
    }
    
    if(curr1){
        new_LL->next = curr1;
    }
    if(curr2){
        new_LL->next = curr2;
    }
    return dummy->next;
}
    
Node * mergeKLists(Node *arr[], int K)
{
    // Your code here
    
    if(K<2){
        return arr[0];
    }
    Node* l1 = arr[0];
    Node* l2 = arr[1];
    Node* merged_list = merge(l1,l2);
    for(int i=2;i<K;i++){
        merged_list = merge(merged_list,arr[i]);
    }
    return merged_list;
}
