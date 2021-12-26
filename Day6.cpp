#include <bits/stdc++.h>
using namespace std;


// Maximum of all subarrays of size k 
vector <int> max_of_subarrays(int *arr, int n, int k)
{
    // your code here
    vector<int> ans;
    deque<int> dq;
    for(int i=0;i<k;i++){
        while(dq.empty() == false && arr[i]>=arr[dq.back()]){
            // Popping out all smaller elements
            dq.pop_back();
        }
        dq.push_back(i);
    }
    
    for(int i=k;i<n;i++){
        ans.push_back(arr[dq.front()]);

        // If front element does not fall in current window pop it out
        while(dq.empty()==false && dq.front()<=(i-k)){
            dq.pop_front();
        }
        // Popping out all the maller elements
        while(dq.empty()==false && arr[i]>=arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(arr[dq.front()]);
    return ans;
}

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
     vector<long long> ans;
     deque<long long> dq;
     for(int i=0;i<K;i++){
         // Push only -ve elements
         if(A[i]<0){
            dq.push_back(i);
         }
     }
     for(int j=K;j<N;j++){
         if(dq.empty()){
             ans.push_back(0);
         }else{
             ans.push_back(A[dq.front()]);
         }
         
         // If front element does not fall in current window pop it out
         if(!dq.empty() && dq.front()<=j-K){
             dq.pop_front();
         }
         if(A[j]<0){
             dq.push_back(j);
         }
     }
     if(dq.empty()){
         ans.push_back(0);
     }else{
         ans.push_back(A[dq.front()]);
     }
     return ans;
 }


// Problem
// You are given a string S. Every sub-string of identical letters is replaced by a single instance of that letter followed by the hexadecimal representation of the number of occurrences of that letter. Then, the string thus obtained is further encrypted by reversing it [ See the sample for more clarity ]. Print the Encrypted String.

string encryptString(string S) {
    // code here
    reverse(S.begin(),S.end());
    string res1 = "";
    int n = S.length();
    for(int i=0;i<n;){
        string res = "";
        int store = i;
        int cnt = 0;
        char val = S[i];
        while(S[i] == val){
            cnt++;
            i++;
        }
        res+= S[store];
        stringstream sstream;
        sstream << hex << cnt;
        string result = sstream.str();
        reverse(result.begin(),result.end());
        res+= result;
        reverse(res.begin(),res.end());
        res1+= res;
    }
    
    return res1;
}