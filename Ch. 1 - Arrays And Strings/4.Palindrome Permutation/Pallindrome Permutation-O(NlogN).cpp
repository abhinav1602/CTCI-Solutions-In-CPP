#include<bits/stdc++.h>

using namespace std;
int main()
 {
	//code
    int t;
    cin>>t;
    while(t--){
        map <char, int> m;
        string s;
        cin>>s;

        int len = s.length();

        for(int i=0; i<len; i++){
        	m[s[i]]++;
        }

		int odd_count = 0;
        for(auto it=m.begin(); it!=m.end(); it++){
        	// cout<<it->first<<" : "<<it->second<<" ";
        	
        	//zero evaluates to true in cpp
        	if(it->second%2)
        		odd_count++;
        }
        
        // if the number of characters having odd count is greater than 1 then it cannot be a pallindrome
        if(odd_count >=2 || len==1)
        	cout<<"Not a pallindrome permutation";
        else
        	cout<<"It is a pallindrome permutation";
        
        cout<<"\n";
    } 
	return 0;
}