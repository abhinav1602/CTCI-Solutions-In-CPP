#include<bits/stdc++.h>

using namespace std;
int main()
 {
	//code
    int t;
    cin>>t;
    while(t--){
        cin.ignore();
        string s;
        getline(cin, s);
        
        int len;
        cin>>len;
        
        // cout<<s<<l<<"\n";
        
        int spaces = 0;
        
        for(int i=0; i<len; i++){
            if(s[i]==' ')
                spaces++;
        }

        // cout<<"Total spaces:"<<spaces<<"\n";
        
        /* 
        Each space has to be replaced by %20 i.e, total 3 characters in one space
        there we need two additional space for replacing ' ' with %20
        */
        s.resize(len + spaces*2, ' ');
        int new_len = s.length();
        int j=new_len;
        
        // cout<<j<<"\n";
        
        for(int i=len-1; i>0; i--){
            if(s[i]==' '){
                s[j-1]='0';
                s[j-2]='2';
                s[j-3]='%';
                j-=3;
            }
            else{
                s[j-1]=s[i];
                j-=1;
            }
        }
        cout<<s<<"\n";
    } 
	return 0;
}