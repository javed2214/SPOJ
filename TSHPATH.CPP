// TSHPATH - The Turtle's Shortest Path

#include<bits/stdc++.h>
using namespace std;
#define MX 100001
typedef pair<int,int> P;

vector<pair<int,int>> g[MX];
int dis[MX];
int vis[MX];

void clearGraph(){

	for(int i=0;i<MX;i++){
		g[i].clear();
	}
}

int dijkstra(int u, int dest){

	for(int i=0;i<MX;i++){
		vis[i]=0;
		dis[i]=1e8;
	}
	priority_queue<P,vector<P>,greater<P>> pq;

	dis[u] = 0;
	pq.push({0,u});

	while(!pq.empty()){

		int temp = pq.top().second;
		pq.pop();

		for(auto it:g[temp]){

			int v = it.first;
			int w = it.second;

			if(dis[v] > dis[temp] + w){
				dis[v] = dis[temp] + w;
				pq.push({dis[v],v});
			}
		}
	}
	if(dis[dest] == 1e8) return -1;
	return dis[dest];
}

int main(){

	int test;
	cin>>test;

	while(test--){

		unordered_map<string,int> Map;

		int n,p=1;
		cin>>n;

		while(n--){

			string s;
			cin>>s;
			Map[s] = p;
			int k;
			cin>>k;
			while(k--){

				int v,w;
				cin>>v>>w;

				g[p].push_back({v,w});
				g[v].push_back({p,w});
			}
			p++;
		}
		int x;
		cin>>x;
		while(x--){

			string s1,s2;
			cin>>s1>>s2;

			int u = Map[s1];
			int v = Map[s2];

			cout<<dijkstra(u,v)<<"\n";
		}
		clearGraph();
	}
	return 0;
}