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


// Interleave the first half of the queue with second half
void fun(queue<int> q){
	stack<int> st;
	int n = q.size()/2;

	// Add the first half elements to stack
	for(int i=0;i<n;i++){
		st.push(q.front());
		q.pop();
	}

	// Add the first half elements back to queue
	while(!st.empty()){
		q.push(st.top());
		st.pop();
	}

	// Add the second half to stack
	for(int i=0;i<n;i++){
		st.push(q.front());
		q.pop();
	}
	// pick the elements one by one first from stack and then from queue
	while(!st.empty()){
		int curr_q = q.front();
		int curr_st = st.top();
		q.pop();
		st.pop();
		q.push(curr_st);
		q.push(curr_q);
	}
	// Reverse the queue
	while(!q.empty()){
		st.push(q.front());
		q.pop();
	}
	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
}

int main(){
	queue<int> q;
	q.push(11);
	q.push(12);
	q.push(13);
	q.push(14);
	q.push(15);
	q.push(16);
	fun(q);
}

int main(){
    int n = 9;
    vector<int> arr = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int l = 0;
    int h = n-1;
    while(l<h){
        if(arr[l]<0 && arr[h]>0){
            l++;
            h--;
        }else if(arr[l]>0 && arr[h]<0){
            swap(arr[l], arr[h]);
            l++;
            h--;
        }else if(arr[l]<0 && arr[h]<0){
            l++;
        }else if(arr[l]>0 && arr[h]>0){
            h--;
        }
    }
    for(int x: arr){
        cout << x << " ";
    }
    cout << "\n";
}


// First non-repeating character in a stream 
string FirstNonRepeating(string A){
    // Code here
    int n = A.length();
    string ans = "";
    queue<char> q;
    vector<int> arr(26);
    for(int i=0;i<A.length();i++){
        arr[A[i] - 'a']++;
        if(arr[A[i] - 'a'] == 1){
            q.push(A[i]);
        }
        while(!q.empty() && arr[q.front() - 'a'] != 1){
            q.pop();
        }
        if(q.empty()){
            ans+= '#';
        }else{
            ans+= q.front();
        }
    }
    return ans;
}