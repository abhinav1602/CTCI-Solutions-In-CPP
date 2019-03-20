#include <bits/stdc++.h>
using namespace std;

int a[1000][1000];

void transpose(int n){
	int temp;

	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++) {
			temp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = temp;
		}
	}
}


void interchange(int n){
	int temp;
	for(int i=0; i<n; i++){
		for(int j=0; j<(n/2); j++){
			temp = a[i][j];
			a[i][j] = a[i][(n-j)-1];
			a[i][(n-j)-1] = temp;
		}
	}
}

int main(){ 
	int t;
	cin>>t;

	while(t--){
		// size of matrix
		int n;
		cin>>n;

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>a[i][j];
			}
		}
		
		/*
		if you transpose a matrix and then 
		interchange columns on both sides, the matrix is rotated by 90
		*/
		transpose(n);
		interchange(n);
		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout<<a[i][j]<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";
		

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout<<a[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}