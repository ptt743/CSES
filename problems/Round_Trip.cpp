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
		cin>>a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> path(n+1,-1);
	vector<int> state(n+1, 0);
	int endcycle = -1;
	int startcycle = -1;

	function<bool(int,int)> dfs =[&](int s, int pre){
		state[s] = 1;
		for(int i =0;i< adj[s].size();i++){
			int u = adj[s][i];
			if(u==pre) continue;
			if(state[u]==0){
				path[u] = s;
				if(dfs(u,s)) return true;
			} else if(state[u]==1){
				startcycle = s;
				endcycle = u;
				return true;
			}
		}
		state[s] = 2;
		return false;
	};
	for(int k =1;k<=n;k++){
		if(state[k]==0){
			if(dfs(k,-1)) break;
		}
	}
	if(startcycle ==-1) cout<< "IMPOSSIBLE"<<endl;
	else {
		vector<int> result;
		int temp = startcycle;
		result.push_back(startcycle);
		while(startcycle!= endcycle){
			startcycle = path[startcycle];
			result.push_back(startcycle);
		}
		result.push_back(temp);
		cout<< result.size() <<endl;
		for(int i =0;i< result.size(); i++) cout<< result[i]<<" ";
		cout<< endl;

	}
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
