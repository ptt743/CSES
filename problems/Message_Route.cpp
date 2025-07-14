#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<cmath>
#include<deque>
#include<functional>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	int n,m;
	cin>> n >> m;
	vector<vector<int>> adj(n+1, vector<int>());
	vector<bool> visited(n+1, false);
	vector<int> path(n+1,0);
	vector<int> len(n+1,0);
	while(m--){
		int a, b;
		cin>> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	function<void(int)> bfs=[&](int s){
		queue<int> qq;
		qq.push(s);
		visited[s] = true;
		len[s] = 1;
		path[s] = s;
		while(!qq.empty()){
			int front = qq.front();
			qq.pop();
			for(int i =0;i< adj[front].size();i++){
				int u = adj[front][i];
				if(visited[u]==false){
					path[u] = front;
					len[u] = len[front]+1;
					visited[u] = true;
					qq.push(u);
				}
			}
		}
	};
	bfs(1);
	if(len[n] == 0) cout<<"IMPOSSIBLE"<<endl;
	else {
		cout<< len[n]<<endl;
		int index = n;
		deque<int> dq;
		dq.push_front(n);
		while(1){
			index = path[index];
			dq.push_front(index);
			if(path[index] == index) break;
		}
		while(!dq.empty()){
			cout<< dq.front()<<" ";
			dq.pop_front();
		}

	}

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
