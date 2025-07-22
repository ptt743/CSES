#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<cmath>
#include<functional>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	int n,m;
	cin >> n >> m;
	struct node {
		int index;
		long long val;
		bool used;
	};
	struct cmp{
		bool operator () (node a, node b){
			return a.val > b.val;
		}
	};
	vector<vector<pair<int,long long>>> adj(n+1, vector<pair<int,long long>>());
	while(m--){
		int a,b;
		long long c;
		cin>> a >> b >> c;

		adj[a].push_back({b,c});
	}
	priority_queue<node, vector<node>, cmp> pq;
	vector<vector<long long>> dist(n+1, vector<long long>(2,2e14 +1));
	dist[1]={0,0};
	pq.push({1,0ll,false});

	while(!pq.empty()){
		node top = pq.top();
		pq.pop();
		int u = top.index;
		long long cost = top.val;
		bool used = top.used;
		if(cost != dist[u][used]) continue;

		for(int i =0;i< adj[u].size();i++){
			int v = adj[u][i].first;
			long long price = adj[u][i].second;
			if(cost + price< dist[v][used]){
				dist[v][used] = cost + price;
				pq.push({v, dist[v][used], used });
			}
			if(!used && (cost + price/2) < dist[v][true]){
				dist[v][true] = cost + price/2;
				pq.push({v, dist[v][true], true});
			}
		}
	}
	cout<< dist[n][true]<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
