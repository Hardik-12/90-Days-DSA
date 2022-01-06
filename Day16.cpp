#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};


// Merge sort for Linked List

Node* merge(Node* l1,Node* l2){
    if(l1 == NULL || l2 == NULL){
        return (l1 == NULL) ? l2 : l1;
    }
    Node* dummy = new Node(-1);
    Node* new_node = dummy;
    Node* curr1 = l1;
    Node* curr2 = l2;
    while(curr1 && curr2){
        if(curr1->data <= curr2->data){
            new_node->next = curr1;
            curr1 = curr1->next;
        }else{
            new_node->next = curr2;
            curr2 = curr2->next;
        }
        
        new_node = new_node->next;
    }
    while(curr1){
        new_node->next = curr1;
        curr1 = curr1->next;
        new_node = new_node->next;
    }
    
    while(curr2){
        new_node->next = curr2;
        curr2 = curr2->next;
        new_node = new_node->next;
    }
    return dummy->next;
}

Node* find_middle(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


Node* mergeSort(Node* head) {
    // your code here
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* mid = find_middle(head);
    Node* store = mid->next;
    mid->next = NULL;
    Node* first = mergeSort(head);
    Node* second = mergeSort(store);
    return merge(first,second);
}



// rotten oranges problem

int rotten_oranges(vector<vector<int>> &grid){
    if(grid.size() == 0){
        return -1;
    }

    int cnt = 0; // To count if the cell which are non-empty are equal to actual count
    int cnt_non_empty = 0; // Actual count
    int time_to_rot = 0; // Time taken if all oranges can be rot
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 2){
                q.push(make_pair(i,j));
                cnt_non_empty++;
            }else if(grid[i][j] == 1){
                cnt_non_empty++;
            }
        }
    }

    int dx[4] = {0,0,-1,1}; // Calculating adjacent coordinates
    int dy[4] = {1,-1,0,0}; // Calculating adjacent coordinates
    while(!q.empty()){
        int c = q.size();
        cnt+= c;
        for(int j=0;j<c;j++){
            int f = q.front().first;
            int s = q.front().second;
            for(int i=0;i<4;i++){
                int n_x = f + dx[i];
                int n_y = s + dy[i];
                if(n_x < 0 || n_y < 0 || n_x >= n || n_y >= m || grid[n_x][n_y] != 1){
                    continue;
                }
                grid[n_x][n_y] = 2;
                q.push(make_pair(n_x,n_y));
            }
        }
        if(!q.empty()){
            time_to_rot++;
        }
    }
    return (cnt == cnt_non_empty) ? time_to_rot : -1;
}

int main(){

}