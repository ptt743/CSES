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

	struct edge{
		int a;
		int b;
		long long c;
	};
	vector<edge> edges;
	for(int i = 0;i<m;i++){
		int a,b;
		long long c;
		cin>> a >> b >> c;
		edges.push_back({a,b,c});
	}

	long long INF = 1LL<<60;
	vector<long long> dist(n+1,0);
	vector<int> parent(n+1,-1);
	int x = -1;
	for(int i =0; i<n;i++){
		x = -1;
		for(edge &e: edges){
			if(dist[e.a] + e.c < dist[e.b]){
				dist[e.b] = dist[e.a] + e.c;
				parent[e.b] = e.a;
				x = e.b;
			}
		}
	}

	if(x!=-1){
		cout<<"YES"<<endl;
		int y = x;

		for(int i = 0;i< n;i++) y = parent[y];
		vector<int> cyc;
		for(int cur = y;;){
			cyc.push_back(cur);
			cur = parent[cur];
			if(cur == y) break;
		}
		cyc.push_back(y);
		reverse(cyc.begin(), cyc.end());
		for(int node: cyc) cout<< node<<" ";
	} else cout<<"NO"<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
