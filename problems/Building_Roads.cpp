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
struct DSU{
	vector<int> path;
	vector<int> size;
	DSU(int n){
		path = vector<int>(n,0);
		size = vector<int>(n,1);
		for(int i =0;i< n;i++) path[i] = i;
	}
	int find(int u){
		return (path[u]==u) ? u : path[u] = find(path[u]);
	}
	void unite(int a, int b){
		int pa = find(a);
		int pb = find(b);
		if(pa == pb) return;
		if(size[pb]>size[pa]) swap(pa,pb);
		size[pa]+=size[pb];
		path[pb] = pa;
	}
};
void solve(){
	int n, m;
	cin>> n >> m;
	DSU ds = DSU(n);
	while(m--){
		int a,b;
		cin>> a >> b;
		ds.unite(a-1,b-1);
	}
	vector<int> rep;
	for(int i =0;i<n;i++){
		if(ds.find(i) ==i){
			rep.push_back(i);
		}
	}
	cout<< rep.size()-1<<endl;
	for(int i =1;i< rep.size();i++) cout<< rep[0]+1<<" "<<rep[i]+1<<endl;
}
void solve2(){
	int n, m;
	cin>> m >> n;
	vector<bool> visited(m,false);
	vector<vector<int>> adj(m, vector<int>());

	function<void(int)> dfs=[&](int s){
		visited[s] = true;
		for(int i = 0;i< adj[s].size();i++){
			int u = adj[s][i];
			if(visited[u]==false) dfs(u);
		}
	};

	while(n--){
		int a, b;
		cin>> a >> b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	vector<int> req;
	for(int i =0;i< m;i++){
		if(!visited[i]){
			req.push_back(i);
			dfs(i);
		}
	}
	cout<< req.size()-1<<endl;;
	for(int i =1;i< req.size();i++) cout<< req[0]+1<<" "<<req[i]+1<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve2();
    return 0;
}
