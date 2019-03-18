#include<bits/stdc++.h>
using namespace std;

// checks if there is only one one different in both arrays
bool oneReplaceAway(string s1, string s2){
	bool firstChangeDone = false;
	int l1 = s1.length();
	// l1 == l2 already
	// int l2 = s2.length();
	int l2 = l1;
	int i=0, j=0;

	while(i<l1 && j<l2){
		if(s1[i] != s2[j]){
			// if first change is already checked then return false as there are more than one dissimilarities
			if(firstChangeDone){
				//cout<<"IGI@"<< i<<" "<<j<<"\n";
				return false;	
			}
			firstChangeDone = true;
		}
		i++;
		j++;
	}
	return true;
}


// checks if one word can be added to one string to create the other one
bool oneInsertAway(string s1, string s2){
	bool firstChangeDone = false;
	int l1 = s1.length();
	int l2 = s2.length();

	int i=0, j=0;

	while(i<l1 && j<l2){
		if(s1[i]!=s2[j]){
			// if the chars at i and j are not equal and i!=j, that means one change is already checked, i.e., it is the second change
			if(i!=j)
				return false;
			j++;
		}
		else{
			i++;
			j++;
		}
	}
	return true;
}

// checks of two strings are One Edit Away
bool oneEditAway(string s1, string s2) {
	int l1 = s1.length();
	int l2 = s2.length();

	// cout<<s1<<" - "<<l1<<"\n"<<s2<<" - "<<l2<<"\n"<<(l1==l2)<<"\n";
	if(l1 == l2){
		return oneReplaceAway(s1, s2);
	}
	else if(l1+1 == l2){
		return oneInsertAway(s1, s2);
	}
	else if(l2+1 == l1){
		return oneInsertAway(s2, s1);
	}
	else
		return false;
}


int main(){
	int t;
	cin>>t;

	while(t--){
		string s1,s2;
		cin>>s1>>s2;

		// cout<<oneEditAway(s1, s2)<<"\n";
		string ans = oneEditAway(s1, s2)==1?"One Edit Awway":"Not one Edit Away";
		cout<<ans<<"\n";
	}
	return 0;
}
