// SUMTRIAN - Sums in Triangle (SPOJ)

#include<bits/stdc++.h>
using namespace std;

int main(){

	int test;
	cin>>test;

	while(test--){

		int row,p=1;
		cin>>row;
		int a[row][row];

		for(int i=0;i<row;i++){
			for(int j=0;j<p;j++){
				cin>>a[i][j];
			}
			p++;
		}
		for(int i=row-2;i>=0;i--){
			for(int j=0;j<=i;j++)
				a[i][j] += max(a[i+1][j], a[i+1][j+1]);
		}
		cout<<a[0][0]<<"\n";
	}
	return 0;
}