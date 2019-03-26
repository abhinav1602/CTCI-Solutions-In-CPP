#include<bits/stdc++.h>
using namespace std;


// checks if s2 is a substring of s1 in O(N)
bool isSubstring(string s1, string s2){
	cout<<s1<<" "<<s2<<"\n";

	size_t found = s1.find(s2);

	if(found != string::npos){
		// cout<<"found at "<<found<<"\n";
		return true;
	}
	return false;
}


// checks if s2 is a rotation of s1
bool checkIfRotation(string s1, string s2){
	if(s1.length() == s2.length() && s1.length()>0){
		string s3 = s1+s1;
		if(isSubstring(s3, s2))
			return true;
	}
	return false;
}


int main(){
	int t;
	cin>>t;

	while(t--){
		string s1, s2;
		cin>>s1>>s2;

		bool isRotation = checkIfRotation(s1, s2);	

		// cout<<isRotation<<"\n";

		if(isRotation)
			cout<<"Is Rotation";
		else
			cout<<"Not a rotation";

		cout<<"\n";
	}
	return 0;
}