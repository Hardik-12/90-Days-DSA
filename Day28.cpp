#include <bits/stdc++.h>
using namespace std;

// Link->https://leetcode.com/contest/weekly-contest-276/problems/divide-a-string-into-groups-of-size-k/
vector<string> divideString(string s, int k, char fill) {
    int n = s.length();
    vector<string> ans;
    if(n<k){
        string res = "";
        for(int i=0;i<n;i++){
            res+= s[i];
        }
        while(res.length()!=k){
            res+= fill;
        }
        ans.push_back(res);
    }else{
        string res = "";
        int j = 0;
        while(true){
            bool flag = true;
            res+= s[j];
            if(res.length() == k){
                ans.push_back(res);
                res = "";
                flag = false;
            }
            if(j == s.length()-1){
                if(flag == true){
                    while(res.length()!=k){
                        res.push_back(fill);
                    }
                    ans.push_back(res);
                    break;
                }else{
                    break;
                }
            }
            j++;
        }
    }
    return ans;
}

// Minimum Moves to Reach Target Score
int minMoves(int target, int maxDoubles) {
    if(target == 1){
        return 0;
    }else if(maxDoubles == 0){
        return target - 1;
    }else{
        int no_of_operations = 0;
        while(true){
            if(target&1){
                target-= 1;
                no_of_operations++;
                if(target == 1){
                    break;
                }
            }else{
                if(maxDoubles == 0){
                    return no_of_operations + target - 1;
                }
                target/= 2;
                no_of_operations++;
                if(target == 1){
                    break;
                }
                maxDoubles--;
                
            }
        }
        return no_of_operations;
    }
}