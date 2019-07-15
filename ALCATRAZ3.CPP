// ALCATRAZ3 - THE HONEYCOMB MAZE

#include<bits/stdc++.h>
using namespace std;

char a[101][101];
int vis[101][101];
int p,q,k;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int dfs(int x, int y, int n, int m, int s){

	if(vis[x][y]){
		if(p==x and q==y and s>=k)
			return 1;
		return 0;
	}
	
	vis[x][y]=1;

	for(int i=0;i<4;i++){
		int xx=x+dx[i];
		int yy=y+dy[i];

		if(xx>=0 and yy>=0 and xx<n and yy<m and a[xx][yy]=='.'){
			if(dfs(xx,yy,n,m,s+1))
				return 1;
		}
	}
	vis[x][y]=0;
	return 0;
}

int main(){

	int  n,m;
	cin>>n>>m;

	cin>>k;

	int x,y;
	cin>>x>>y;
	--x;--y;
	p=x;q=y;

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>a[i][j];

	if(dfs(x,y,n,m,0)) cout<<"YES";
	else cout<<"NO";

	return 0;
}