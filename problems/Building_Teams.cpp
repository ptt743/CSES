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
	int n, m;
	cin>> n >> m;
	vector<vector<int>> adj(n+1, vector<int>());
	while(m--){
		int a, b;
		cin>> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<bool> visited(n+1, false);
	vector<int> color(n+1,0);
	bool check = true;
	function<void(int)> bfs=[&](int s){
		queue<int> qq;
		visited[s] = true;
		color[s] = 1;
		qq.push(s);
		while(!qq.empty()){
			int front = qq.front();
			qq.pop();
			for(int i =0;i< adj[front].size();i++){
				int u = adj[front][i];
				if(!visited[u]){
					visited[u] = true;
					color[u] = (color[front]==1)?2:1;
					qq.push(u);
				} else if( color[u]== color[front]) {
					check = false;
					return;
				}

			}
		}
	};
	for(int k =1;k<=n;k++)
		if(!visited[k])
			bfs(k);
	if(!check) cout<<"IMPOSSIBLE"<<endl;
	else {
		for(int i=1;i<=n;i++) cout<< color[i]<<" ";
	}
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
