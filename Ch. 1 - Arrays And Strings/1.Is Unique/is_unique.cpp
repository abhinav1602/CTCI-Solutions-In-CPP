#include<bits/stdc++.h>
using namespace std;


//case insensitive check
bool isUnique_WithoutDS(string s){
	sort(s.begin(), s.end());

	int len = s.length();

	if(len == 1)
		return true;

	for(int i=1; i<len; i++){
		if(tolower(s[i]) ==tolower(s[i-1]))
			return false;
	}
	return true;
}

//case sensitive check
bool isUnique_i_WithoutDS(string s){
	sort(s.begin(), s.end());

	int len = s.length();

	if(len == 1)
		return true;

	for(int i=1; i<len; i++){
		if(s[i]==s[i-1])
			return false;
	}
	return true;
}

int main(){
	string s = "Abhinav";
	// cin>>s;

	string case_sensitive_ans = isUnique_i_WithoutDS(s)==1?"Unique":"Not Unique";
	cout<<"When lower Case and Uppercase are considered different: "<< case_sensitive_ans <<"\n";

	string case_insensitive_ans = isUnique_WithoutDS(s)==1?"Unique":"Not Unique";
	cout<<"When lower Case and Uppercase are considered same: "<< case_insensitive_ans <<"\n";
}


