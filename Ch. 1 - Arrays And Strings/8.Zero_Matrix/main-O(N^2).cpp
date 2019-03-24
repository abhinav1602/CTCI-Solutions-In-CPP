#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];

int makeRowZero(int row_index, int cols){
	for(int i=0; i<cols; i++)
		a[row_index][i] = 0;	
}

int makeColZero(int col_index, int rows){
	for(int i=0; i<rows; i++)
		a[i][col_index] = 0;	
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int m,n;
		cin>>m>>n;

		// for storing row,column containing zeroes
		set<int> row;
		set<int> col; 

		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				cin>>a[i][j];
				if(a[i][j]==0){
					row.insert(i);
					col.insert(j);
				}
			}
		}

		for(auto it=row.begin(); it!=row.end(); it++){
			// cout<<*it<<" ";
			makeRowZero(*it, m);
		}
		cout<<"\n";
		for(auto it=col.begin(); it!=col.end(); it++){
			// cout<<*it<<" ";
			makeColZero(*it, n);
		}

		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				cout<<a[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}