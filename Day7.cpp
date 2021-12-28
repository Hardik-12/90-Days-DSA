#include <bits/stdc++.h>
using namespace std;

// As we go down the level it represents column number
//                         N=4
//         0           1           2           3    (Choices for 1st queen->Here 0,1,2,3 represents row index)
//     01  02  03   10  12  13  20  21  23   30  31  32 (Now 2nd queen can be placed at row index 1)
// 012 013 021 023 ......................................
// .......................................................
// ..........................................................



// N Queen Problem
bool is_safe(int row,int column,vector<vector<int>> &board,int n){
	// Checking if the queen falls in same row.
	for(int i=0;i<column;i++){
		if(board[row][i]){
			return false;
		}
	}
	// Checking upper diagonal.
	for(int i=row,j=column;i>=0 && j>=0;i--,j--){
		if(board[i][j]){
			return false;
		}
	}

	// Checking Lower diagonal.
	for(int i=row,j=column;i<n && j>=0;i++,j--){
		if(board[i][j]){
			return false;
		}
	}
	return true;
}


bool solveRec(int column,int n,vector<vector<int>> &board){
	if(column == n){
		return true;
	}
	for(int i=0;i<n;i++){
		// Checking if queen to be placed is not under attack.
		if(is_safe(i,column,board,n)){
			board[i][column] = 1;
			if(solveRec(column+1,n,board)){
				return true;
			}
			board[i][column] = 0;
		}
	}
	return false;
}

// Sum of two elements with sum nearest to zero

int closestToZero(int arr[], int n){
	sort(arr, arr+n);
	int l = 0;
	int h = n-1;
	int res = arr[0] + arr[n-1];
	// Using 2 pointer to check how much minimum sum is obtained
	while(l<h){
		int sum = arr[l] + arr[h];
		if(sum == 0){
			return 0;
		}
		if(sum<0){
			l++;
		}else{
			h--;
		}
		if(abs(sum) < abs(res)){
			res = sum;
		}
		if(abs(sum) == abs(res)){
			res = max(res,sum);
		}
	}
	return res;
}

int main(){
	int n = 4;
	int column = 0;
	vector<vector<int>> board(n);
	for (int i=0;i<n;i++) {
        board[i].resize(n);
    }
	solveRec(column,n,board);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}