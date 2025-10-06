#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<map>
#include<cmath>
#include<functional>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	int n,m;
	cin>> n >> m;

	struct egde{
		int u;
		int v;
		long long w;
	};
	vector<vector<int>> g(n+1), gr(n+1);
	vector<edge> edges;
	for(int i =0;i< n;i++){
		int a,b; long long c;
		cin >> a >> b >> c;
		edges.push_back({a,b,-c});
		g[a].push_back(b);
		gr[b].push_back(a);
	}


	vector<bool> beginend(n+1, false);
	vector<bool> endbegin(n+1, false);
	{
		queue<int> qq;
		qq.push(1);
		beginend[1] = true;
		while(!qq.empty()){
			int front = qq.front();
			qq.pop();
			for(int u : g[front]){
				if(beginend[u]==false){
					beginend[u] = true;
					qq.push(u);
				}
			}

		}
	}
	{
		queue<int> qq;
		qq.push(n);
		endbegin[n] = true;
		while(!qq.empty()){
			int front = qq.front();
			qq.pop();
			for(int u : gr[front]){
				if(endbegin[u]==false){
					endbegin[u] = true;
					qq.push(u);
				}
			}

		}
	}

	vector<ll> dist(n+1, INF);
   	dist[1] = 0;
    	for (int it = 1; it <= n-1; ++it) {
		bool any = false;
		for (const auto &e : edges) {
	    	if (dist[e.u] == INF) continue;
	    	ll cand = dist[e.u] + e.w;
			if (cand < dist[e.v]) {
				dist[e.v] = cand;
				any = true;
			}
		}
		if (!any) break;
    	}

    // Detect positive-cycle (in x) affecting path 1->n
	for (const auto &e : edges) {
		if (dist[e.u] == INF) continue;
		if (dist[e.u] + e.w < dist[e.v]) {
		    if (beginend[e.u] && endbegin[e.v]) {
			cout << -1 << '\n'; // +∞
			return 0;
		    }
		}
	}

    cout << -dist[n] << '\n'; // finite best score
	    return 0;





}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
