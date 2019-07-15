// TRVCOST - Travelling Cost

#include<bits/stdc++.h>
using namespace std;
#define MX 1001
typedef pair<int,int> P;

vector<pair<int,int>> g[MX];
int vis[MX];
int dis[MX];

void dijkstraAlgo(int src){

	priority_queue<P,vector<P>,greater<P>> pq;
	for(int i=0;i<MX;i++){
		vis[i]=0;
		dis[i]=1e8;
	}
	dis[src]=0;
	pq.push({0,src});

	while(!pq.empty()){

		int temp=pq.top().second;
		pq.pop();

		if(vis[temp]) continue;
		vis[temp]=1;

		for(auto it:g[temp]){

			int v=it.first;
			int w=it.second;

			if(dis[v] > dis[temp] + w){
				dis[v] = dis[temp] + w;
				pq.push({dis[v],v});
			}
		}
	}
}

int main(){

	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		int u,v,w;
		cin>>u>>v>>w;

		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}

	int src;
	cin>>src;

	dijkstraAlgo(src);

	int q;
	cin>>q;

	while(q--){

		int x;
		cin>>x;
		if(x==src) cout<<"0\n";
		else if(dis[x]==1e8) cout<<"NO PATH\n";
		else cout<<dis[x]<<"\n";
	}
	return 0;
}