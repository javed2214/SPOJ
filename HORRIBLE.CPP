// HORRIBLE - Horrible Queries

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MX 1000005

ll a[MX];
ll tree[4*MX];
ll lazy[4*MX];

void reset(){

	for(ll i=0;i<MX;i++) a[i] = 0LL;
	for(ll i=0;i<4*MX;i++){
		tree[i] = 0LL;
		lazy[i] = 0LL;
	}
}

void buildTree(ll start, ll end, ll index){

	if(start == end){
		tree[index] = a[start];
		return;
	}
	ll mid = (start + end) / 2;
	buildTree(start, mid, 2 * index);
	buildTree(mid + 1, end, 2 * index + 1);
	tree[index] = tree[2 * index] + tree[2 * index + 1];
}	

void lazyUpdate(ll start, ll end, ll l, ll r, ll val, ll index){

	if(lazy[index] != 0){

		tree[index] += lazy[index] * (1LL * (end - start + 1));
		
		if(start != end){
			lazy[2 * index] += lazy[index];
			lazy[2 * index + 1] += lazy[index];
		}
		
		lazy[index] = 0;
	}
	
	if(start > end or l > end or r < start)
		return;

	if(start >= l and end <= r){

		tree[index] += val * (1LL * (end - start + 1));

		if(start != end){
			lazy[2 * index] += val;
			lazy[2 * index + 1] += val;
		}
		return;
	}
	ll mid = (start + end) / 2;
	lazyUpdate(start, mid, l, r, val, 2 * index);
	lazyUpdate(mid+1, end, l, r, val, 2 * index + 1);
	tree[index] = tree[2 * index] + tree[2 * index + 1];
}

ll query(ll start, ll end, ll l, ll r, ll index){

	if(start > end or r < start or l > end)
		return 0;

	if(lazy[index] != 0){

		tree[index] += lazy[index] * (1LL * (end - start + 1));

		if(start != end){

			lazy[2 * index] += lazy[index];
			lazy[2 * index + 1] += lazy[index];
		}
		lazy[index] = 0;
	}
	
	if(start >= l and end <= r)
		return tree[index];

	ll mid = (start + end) / 2;
	ll s1 = query(start, mid, l, r, 2 * index);
	ll s2 = query(mid + 1, end, l, r, 2 * index + 1);

	return (s1 + s2);
}

int main(){

	ll test;
	cin>>test;

	while(test--){

		ll n,m;
		cin>>n>>m;

		reset();

		for(ll i=0;i<m;i++){
			ll x;
			cin>>x;
			if(x){
				ll l,r;
				cin>>l>>r;
				cout<<query(1,n,l,r,1)<<endl;
			}else{
				ll l,r,v;
				cin>>l>>r>>v;
				lazyUpdate(1,n,l,r,v,1);
			}
		}
	}
	return 0;
}