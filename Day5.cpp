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


// To check if the cell value contains 1
bool is_safe(vector<vector<bool>> maze,int i,int j,int N){
	if(i<N && j<N && maze[i][j] == 1){
		return true;
	}
	return false;
}

bool solve_maze(vector<vector<bool>> maze,int i,int j,vector<vector<bool>> &sol,int N){
    // If rat reaches end of the cell
	if(i == N-1 && j == N-1){
		sol[i][j] = 1;
		return true;
	}


	if(is_safe(maze,i,j,N)){
        // Making the cell(i,j) = 1 in soln matrix indicating that path exists
		sol[i][j] = 1;
		if(solve_maze(maze,i+1,j,sol,N)){
			return true;
		}else if(solve_maze(maze,i,j+1,sol,N)){
			return true;
		}else{
			sol[i][j] = 0;
		}
	}
	return false;
}

int main(){
	int N = 4;
	vector<vector<bool>> maze = {{1,0,0,0},{1,1,0,1},{0,1,0,0},{1,1,1,1}};
	vector<vector<bool>> sol;
	if(solve_maze(maze,0,0,sol,N) == false){
		return false;
	}else{
		for(int i=0;i<sol.size();i++){
			for(int j=0;j<sol[i].size();j++){
				cout << sol[i][j] << " ";
			}
			cout << "\n";
		}
	}
}

//  Maximum sum after k negations
// Here we must make any +ve element -ve and -ve element +ve find Maximum sum after k negations
long long int maximizeSum(long long int a[], int n, int k)
{
	// Your code goes here
	sort(a,a+n);
	for(long long i=0;i<n;i++){
		if(a[i]<0){
			a[i] = (-1)*a[i];
			k--;
			if(k == 0){
				break;
			}
		}
	}
	sort(a,a+n);
	while(k>0){
		a[0] = (-1)*a[0];
		k--;
	}
	long long sum = 0;
	for(long long i=0;i<n;i++){
		sum+= a[i];
	}
	cout << sum;
}