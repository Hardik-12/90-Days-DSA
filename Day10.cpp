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

// Infix,Prefix and Postfix notation
// ----------------------------------
// Infix: x+y
// Prefix: +xy
// Postfix: xy+

// Advantages of prefix and postfix
// 1.Can be evaluated by traversing the expression exactly once
// 2.Do not require any precedence rules and associativity rules

// Operators    Associativity
// ^			right to left
// *,/          left to right
// +,-          left to right

// e.g. 10 + 20 * 2  = 50->Multiplication has higher precedence
// 	 10 + 2 - 3 -> + and - both have same precedence therfore wefollow left ot right associativity
// 	 2 ^ 1 ^ 2 -> In case of exponentiation we follow right to left

// Infix to Postfix
// 1. a + b * (c-d) -> abcd-*+ 
// 2. a + b * c / d + e -> abc*d/+e+

// Infix to Postfix
bool fun(char str_c,char top_s){
    // Checking if stk top and current character has same precedence
	if((str_c == '*' && top_s == '/') || 
	(str_c == '+' && top_s == '-') || 
	(str_c == '/' && top_s == '*') || 
	(str_c == '-' && top_s == '+') || 
	(str_c == '+' && top_s == '+') || 
	(str_c == '-' && top_s == '-') || 
	(str_c == '*' && top_s == '*') || 
	(str_c == '/' && top_s == '/')){
		return true;
	}
    // Checking if current character has lower precedence than stk top
    else if((str_c == '+' && top_s == '*') || 
	(str_c == '-' && top_s == '*') || 
	(str_c == '+' && top_s == '/') || 
	(str_c == '-' && top_s == '/')){
		return true;
	}
	return false;
}

int main(){
	string res = "a+b*(c-d)";
	string ans = "";
	stack<char> st;
	for(int i=0;i<res.length();i++){
        // If opening bracket we push it to stack
		if(res[i] == '('){
			st.push(res[i]);
		}
        // If closing bracket we pop until we find an opening bracket and pop out opening bracket
        else if(res[i] == ')'){
			while(st.top() != '('){
				int curr = st.top();
				st.pop();
				ans+= curr;
			}
			st.pop();
		}
        // If an operator is found
        else if(res[i] == '+' || res[i] == '-' || res[i] == '*'
			|| res[i] == '/'){
			if(st.empty()){
				st.push(res[i]);
			}else{
				int curr = st.top();
                // Checking if current character has higher precedence than stk top
				if(fun(res[i], curr) == false){
					st.push(res[i]);
				}
                // Checking if current character has lower precedence than stk top
                else{
					while(!st.empty()){
                        // We pop until we find a lower precedence character or same precedence character we push current character afterwards
						char val = st.top();
						if(fun(res[i], val)){
							st.pop();
							ans+= val;
						}else{
							break;
						}
					}
					st.push(res[i]);
				}
			}
		}else{
			ans+= res[i];
		}
	}
	while(!st.empty()){
		int curr = st.top();
		st.pop();
		ans+= curr;
	}
	cout << ans << "\n";
}

// Infix to Prefix
bool fun(char str_c,char top_s){
    // Checking if stk top and current character has same precedence
	if((str_c == '+' && top_s == '+') || 
	(str_c == '-' && top_s == '-') || 
	(str_c == '*' && top_s == '*') || 
	(str_c == '/' && top_s == '/')){
		return true;
	}else if((str_c == '+' && top_s == '*') || 
	(str_c == '-' && top_s == '*') || 
	(str_c == '+' && top_s == '/') || 
	(str_c == '-' && top_s == '/')){
		return true;
	}
	return false;
}

int main(){
	string res = "x*y-z/w*u";
	string ans = "";
	stack<char> st;
	int n = res.length();
	for(int i=n-1;i>=0;i--){
        // If closing bracket we push it to stack
		if(res[i] == ')'){
			st.push(res[i]);
		}
        // If closing bracket we pop until we find an opening bracket and pop out opening bracket
        else if(res[i] == '('){
			while(st.top() != ')'){
				int curr = st.top();
				st.pop();
				ans+= curr;
			}
			st.pop();
		}
        // If an operator is found
        else if(res[i] == '+' || res[i] == '-' || res[i] == '*'
			|| res[i] == '/'){
			if(st.empty()){
				st.push(res[i]);
            }
            // Checking if current character has higher precedence than stk top
            else{
				int curr = st.top();
				if(fun(res[i], curr) == false){
					st.push(res[i]);
				}
                // Checking if current character has lower precedence than stk top
                else{
                    // We pop until we find a lower precedence character or same precedence character we push current character afterwards
					while(!st.empty()){
						char val = st.top();
						if(fun(res[i], val)){
							st.pop();
							ans+= val;
						}else{
							break;
						}
					}
					st.push(res[i]);
				}
			}
		}else{
			ans+= res[i];
		}
	}
	while(!st.empty()){
		int curr = st.top();
		st.pop();
		ans+= curr;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";
}