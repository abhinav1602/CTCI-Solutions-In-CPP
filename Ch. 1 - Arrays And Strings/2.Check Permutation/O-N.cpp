#include<bits/stdc++.h>
using namespace std;

int main(){
	string s1,s2;
	cin>>s1>>s2;

	// for storing length of both strings
	int l1 = s1.length();
	int l2 = s2.length();

	// count stores the count of alphabets in strings(initialized with zero)
	int count_s1[26] = {0}, count_s2[26]={0};

	for(int i=0; i<l1; i++){
		// for the sake of simplicity lets assume that all the characters are lowercase aplhabets only
		count_s1[s1[i]-'a']++;
	}

	for(int i=0; i<l2; i++){
		// for the sake of simplicity lets assume that all the characters are lowercase aplhabets only
		count_s2[s2[i]-'a']++;
	}

	string ans = " ";
	for(int i=0; i<26; i++){
		cout<<count_s1[i]<<" "<<count_s2[i]<<"\n";
		if(count_s1[i]!=count_s2[i]){
			ans = " not ";
			break;
		}
	}

	cout<<"Both strings are"<<ans<<"permutations of each other\n";

}
