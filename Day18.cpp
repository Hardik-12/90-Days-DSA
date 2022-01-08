#include <bits/stdc++.h>
using namespace std;



// Row with max 1s
int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
    int row = INT_MAX;
    int res = 0;
    for(int i=0;i<n;i++){
        vector<int> arr_i = arr[i];
        int l = 0;
        int h = m-1;
        int cnt_1s = 0;
        while(l<=h){
            int mid = (l + h)/2;
            if(arr_i[mid] == 1){
                h = mid-1;
            }else if(arr_i[mid] == 0){
                l = mid+1;
            }
        }
        if(m-l > 0){
            cnt_1s+= (m-l);
        }
        
        if(cnt_1s > res){
            res = cnt_1s;
            row = i;
        }
    }
    if(row == INT_MAX){
        row = -1;
    }
    return row;
    
}

// Spirally traverse a matrix
vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
{
    // code here 
    vector<int> ans;
    int rs = 0;
    int re = r-1;
    int cs = 0;
    int ce = c-1;
    while(rs<=re && cs<=ce){
        for(int i=cs;i<=ce;i++){
            ans.push_back(matrix[rs][i]);
        }
        rs++;
        
        for(int j=rs;j<=re;j++){
            if(rs>re || cs>ce){
                break;
            }
            ans.push_back(matrix[j][ce]);
        }
        ce--;
        
        for(int k=ce;k>=cs;k--){
            if(rs>re || cs>ce){
                break;
            }
            ans.push_back(matrix[re][k]);
        }
        re--;
        
        for(int l=re;l>=rs;l--){
            if(rs>re || cs>ce){
                break;
            }
            ans.push_back(matrix[l][cs]);
        }
        cs++;
        
    }
    return ans;
}