#include<bits/stdc++.h>
using namespace std;

// converts string to encoded string
string encoded(string s){
	int len = s.length();
	char x = s[0];
	int count = 1;

	string ans = "";
	for(int i=1; i<len; i++){
		if(s[i] == s[i-1]){
			count++;
		}
		else{
			ans+=x;
			ans+=to_string(count);
			// cout<<x<<count;
			count = 1;
			x = s[i];
		}
		if(i==len-1){
			ans+=x;
			ans+=to_string(count);
		}
	}

	// return encoded string only if its length is smaller than original else return original
	if (ans.length()<= len)
		return ans;
	else
		return s;	
}


int main(){ 
	int t;
	cin>>t;

	while(t--){
		string s;
		cin>>s;

		string encodes_s = encoded(s);
		cout<<encodes_s<<"\n";
	}
	return 0;
}