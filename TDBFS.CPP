// TDBFS - Searching the Graph

#include<bits/stdc++.h>
using namespace std;
 
vector<vector<int>> res;
vector<int> ans;
 
void BFSTraversal(int root, bool *visited, std::vector<int> *Adj, int n){
 
	visited[root]=true;
	queue <int> q;
	q.push(root);
	while(!q.empty()){
		int temp=q.front();
		q.pop();
		ans.push_back(temp);
		for(auto it:Adj[temp]){
			if(visited[it]==false){
				visited[it]=true;
				q.push(it);
			}
		}
	}
	res.push_back(ans);
	ans.clear();
}
 
void DFSTraversal(int root, bool *visited, std::vector<int> *Adj){
 
	visited[root]=true;
	ans.push_back(root);
	for(auto it:Adj[root]){
		if(visited[it]==false)
			DFSTraversal(it,visited,Adj);
	}
}
 
int main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test,c=1;
	cin>>test;
	while(test--){
 
		int v,x,y,edg;
		int nodes;
		cin>>nodes;
		std::vector<int> Adj[1001];
		while(nodes--){
			cin>>v;
			cin>>edg;
			while(edg--){
				cin>>x;
				Adj[v].push_back(x);
			}
		}
		bool visited[1001];
		int p=1;
		int flag=1;
		while(1){
			memset(visited,false,sizeof(visited));
			cin>>x>>y;
			if(flag){
				ans.push_back(-11);
				res.push_back(ans);
				ans.clear();
				flag=0;
			}
			if(x==0 and y==0) break;
			else if(y==0) DFSTraversal(x,visited,Adj),res.push_back(ans),ans.clear();
			else if(y==1) BFSTraversal(x,visited,Adj,nodes+1);
		}
	}
 
	for(int i=0;i<res.size();i++){
		if(res[i].size()==1 and res[i][0]==-11){
			cout<<"graph "<<c;
			c++;
			cout<<"\n";
			continue;
		}
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j]<<" ";
		}
		cout<<"\n";
	}
 
	return 0;
} 