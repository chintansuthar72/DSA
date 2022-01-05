#include<iostream>
#include<string>
#include<stack>
// #include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
	char x;
	stack<char> st;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '{' || s[i] == '[' || s[i] == '(')
		{
			st.push(s[i]);
			continue;
		}
		if (st.empty())
			return false;
		switch (s[i]) {
		case ')':
			x = st.top();
			st.pop();
			if (x == '[' || x == '{') {
				return false;
			}
			break;
		case '}':
			x = st.top();
			st.pop();
			if (x == '[' || x == '(') {
				return false;
			}
			break;
		case ']':
			x = st.top();
			st.pop();
			if (x == '(' || x == '{') {
				return false;
			}
			break;
		}
	}
	return st.empty();
}


int main() {
	string s = "({}{([])})";
	if (isValid(s))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}