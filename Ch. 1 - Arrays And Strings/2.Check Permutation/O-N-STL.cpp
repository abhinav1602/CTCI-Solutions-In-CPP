#include<bits/stdc++.h>
using namespace std;

int main(){
	string s1,s2;
	cin>>s1>>s2;

	// for storing length of both strings
	int l1 = s1.length();
	int l2 = s2.length();

	map<char, int> ms1,ms2;

	for(int i=0; i<l1; i++){
		ms1[s1[i]]++;
	}

	for(int i=0; i<l2; i++){
		ms2[s2[i]]++;
	}

	// these map stores the count of all the characters in strings
	int m1_size = ms1.size();
	int m2_size = ms2.size();

	string ans = " ";
	
	// cout<<m1_size<<" "<<m2_size;
	if(m1_size!=m2_size){
		ans = " not ";
	}

	else{
		for(auto it = ms1.begin(); it!=ms1.end(); it++){
			// cout<<it->first<<" "<<it->second<<"\n";
			if(ms1[it->first] != ms2[it->first])
				ans = " not ";
		}
	}
	cout<<"\nBoth strings are"<<ans<<"permutations of each other\n";
}