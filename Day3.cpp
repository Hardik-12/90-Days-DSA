#include <bits/stdc++.h>
using namespace std;


// Permutations of a string

// One by one fix character and perform swap in order to get permutation

// i variable is used to keep track of how many varibles are fixed and how many are remaining to be fixed
void permute(string s,int i=0){
	if(i == s.length()-1){
		cout << s << "\n";
		return;
	}

	for(int j=i;j<s.length();j++){
		swap(s[i],s[j]);
		permute(s,i+1);
		swap(s[j],s[i]); // Backtrack to retain original string
	}
}

int main(){
	string s = "ABC";
	permute(s,0);
}

// Tower of Hanoi Problem
// There are 2^n movements for a given n

void toh(int n,char source,char aux,char dest){
	if(n == 1){
		cout << "Move disk " << 1 << " from " << source << " to " << dest << "\n";
		return;
	}

	toh(n-1,source,dest,aux);
	cout << "Move " << "disk " << n << " from tower " <<  source << " to " << dest << "\n";
	toh(n-1,aux,source,dest);
}

int main(){
	int n = 3;
	toh(n,'A','B','C');
}

int digital_root(int n){
    while(n>9){
        n = n%10 + digital_root(n/10);
    }
    return n;
}

int main(){
	int n = 978;
	cout << digital_root(n) << "\n";
}