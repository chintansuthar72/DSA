#include <bits/stdc++.h>
#include <string>
using namespace  std;
int main()
{
	int t,lucky=0,non=0,nn=0;cin >> t;
	long long int arr[t];
	for (int i = 0; i < t; ++i)
	{
		cin>>arr[t];
	}
	for (int i = 0; i < t; ++i)
	{
		string str=to_string(arr[i]);
		int size=sizeof(str);
		int sum=0;
		bool check=true;
		for (int b = 0; b < size; ++b)
		{
			if (str[b]!=4 || str[b]!=7)
			{
				check=false;
			}
		}
		if(check)
			lucky++;
		for (int j = 0; j < size; ++j)
		{
			sum+=str[j];
		}
		if (sum==7 || sum==4)
		{
			for (int k = 0; k < size; ++k)
			{
				if (str[k]!=4 || str[k]!=7)
					nn++;
			}
			non++;
		}
	}
	cout<<lucky<<" "<<non<<" "<<nn<<endl;
	return 0;
}