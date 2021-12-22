#include <bits/stdc++.h>
using namespace std;



int s_of_digits(int n){
    // When all digits are finished
    if(n == 0){
        return 0;
    }
    
    return (n%10 + s_of_digits(n/10));
}


int rope_cutting_problem(int n,int a,int b,int c){
    if(n == 0){
        return 0;
    }

    if(n<0){
        return -1;
    }
    // Taking the maximum of cutting through a,b and c satisfying constraints
    int res = max(max(rope_cutting_problem(n-a,a,b,c),rope_cutting_problem(n-b,a,b,c)),rope_cutting_problem(n-c,a,b,c));
    if(res == -1){
        return -1;
    }
    return res+1;
}

int main()
{
    int n = 897;
    cout << s_of_digits(n) << "\n";
    return 0;
}


void generate_subsets(vector<int> &nums,vector<int> res,int idx,vector<vector<int>> &ans){
        
        // When we reach the size of vector
        if(idx == nums.size()){
            ans.push_back(res);
            res.clear();
            return;
        }
        
        // Not including the current set
        generate(nums,res,idx+1,ans);
        res.push_back(nums[idx]);
        // Including the current set
        generate(nums,res,idx+1,ans);
    }
    
    

int main(){
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans;
        
    vector<int> res;
    
    int idx = 0;
    generate(nums,res,idx,ans);
    for(auto x: ans){
        cout << x << " ";
    }
}
