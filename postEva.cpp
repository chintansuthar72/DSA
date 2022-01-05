#include <iostream>
#include <stack>
#include <string.h>
#include <math.h>
using namespace std;


int infixEva(string s){
	stack<int> st;
	int ans = 0;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' and s[i]<='9'){
			st.push(s[i]-'0'); // make int value
		}
		else{
			int op1,op2;
			switch(s[i]){
				case '+':
					op2 = st.top();
					st.pop();
					op1 = st.top();
					st.pop();
					ans = op1 + op2;
					st.push(ans);
					break;
				case '-':
					op2 = st.top();
					st.pop();
					op1 = st.top();
					st.pop();
					ans = op1 - op2;
					st.push(ans);
					break;
				case '*':
					op2 = st.top();
					st.pop();
					op1 = st.top();
					st.pop();
					ans = op1 * op2;
					st.push(ans);
					break;
				case '/':
					op2 = st.top();
					st.pop();
					op1 = st.top();
					st.pop();
					ans = op1 / op2;
					st.push(ans);
					break;
				case '^':
					op2 = st.top();
					st.pop();
					op1 = st.top();
					st.pop();
					ans = pow(op1,op2);
					st.push(ans);
					break;
			}
		}
	}
	return st.top();
}

signed int main(){

    string s;
    cin >> s;
    cout << infixEva(s) << endl;
    return 0;
}