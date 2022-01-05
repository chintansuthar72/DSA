#include <iostream>
#include <string.h>
using namespace std;
#include<bits/stdc++.h>


void file_i_o(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}


string prefixTOpostfix(string pre) {
	int len = pre.length();
	string tmpArr[len][len];
	int idx=0;
	
	for(int i=len-1; i>=0; i--) {
		if(pre[i] == '+' || pre[i] == '-' || pre[i] == '*' || pre[i] == '/'){
			string op1 = "";
			for(int j=0;tmpArr[idx][j]!='\0'; j++){
				op1+=tmpArr[idx][j];
			}
			idx--;
			string op2 = "";
			for(int j=0;tmpArr[idx][j]!='\0'; j++){
				op2+=tmpArr[idx][j];
			}
			idx--;
			string ans="";
			ans = op1 + op2 + pre[i];
			tmpArr[idx++] = ans;
		}
		else{
			tmpArr[idx++][0] = pre[i];
		}
	}
	string finalans= "";
	for(int i=0; tmpArr[0][i]!='\0'; i++){
		finalans += tmpArr[0][i];
	}
	return finalans;
}

int main(){
	file_i_o();

	string s;
	cin >> s;
	cout << prefixTOpostfix(s) << endl;	
	return 0;
}
