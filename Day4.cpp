#include <bits/stdc++.h>
using namespace std;

// Backtracking


// Naive solution to generate all permutations.
void permute(string s,int i){
    if(i == s.length()-1){
        cout << s << "\n";
        return;
    }

    for(int j=i;j<s.length();j++){
        swap(s[i],s[j]);
        permute(s,i+1);
        swap(s[j],s[i]);
    }
}


// Backtracking solution to generate all permutations not containing 'AB' as substring

bool is_safe(string s,int i,int j){
    if(i!=0 && s[i-1] == 'A' && s[j] == 'B'){
        return false;
    }
    if(s.length() == j+1 && s[j] == 'A' && s[i] == 'B'){
        return false;
    }
    return true;
}

void permute(string s,int i){
    if(i == s.length()-1){
        cout << s << "\n";
        return;
    }

    for(int j=i;j<s.length();j++){
        swap(s[i],s[j]);
        permute(s,i+1);
        swap(s[j],s[i]);
    }
}

int main(){

}