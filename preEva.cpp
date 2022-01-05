#include <iostream>
#include <stack>
#include <string.h>
#include <math.h>
using namespace std;

void file_i_o(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int infixEva(string s){
	stack<int> st;
	int ans = 0;
	for(int i=s.length();i>=0;i--){
		if(s[i]>='0' and s[i]<='9'){
			st.push(s[i]-'0'); // make int value
		}
		else{
			int op1,op2;
			switch(s[i]){
				case '+':
					op1 = st.top();
					st.pop();
					op2 = st.top();
					st.pop();
					ans = op1 + op2;
					st.push(ans);
					break;
				case '-':
					op1 = st.top();
					st.pop();
					op2 = st.top();
					st.pop();
					ans = op1 - op2;
					st.push(ans);
					break;
				case '*':
					op1 = st.top();
					st.pop();
					op2 = st.top();
					st.pop();
					ans = op1 * op2;
					st.push(ans);
					break;
				case '/':
					op1 = st.top();
					st.pop();
					op2 = st.top();
					st.pop();
					ans = op1 / op2;
					st.push(ans);
					break;
				case '^':
					op1 = st.top();
					st.pop();
					op2 = st.top();
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
    file_i_o();

    string s;
    cin >> s;
    cout << infixEva(s) << endl;
    return 0;
}