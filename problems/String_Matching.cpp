#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<map>
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
	cin>> n >> m;
	vector<vector<char>> graph(n, vector<char>(m,'a'));
	pair<int,int> A,B;
	for(int i =0;i< n;i++)
		for(int j =0;j< m;j++){
			cin>> graph[i][j];
			if(graph[i][j]=='A') A = {i,j};
			if(graph[i][j]=='B') B = {i,j};
		}
	vector<int> dx= {1,-1,0,0};
	vector<int> dy= {0,0,-1,1};
	vector<vector<bool>> visited(n,vector<bool>(m,false));
	vector<vector<pair<int,int>>> path(n, vector<pair<int,int>>(m,{0,0}));

	path[A.first][A.second] = A;
	function<void(pair<int,int>)> bfs=[&](pair<int,int> s){
		queue<pair<int,int>> qq;
		qq.push(s);
		visited[s.first][s.second] = true;
		while(!qq.empty()){
			pair<int,int> f = qq.front();
			qq.pop();

			for(int i =0;i< 4;i++){
				int nextx = f.first + dx[i];
				int nexty = f.second + dy[i];
				if(nextx >=0 && nextx <=n 
				   && nexty >=0 && nexty<=m 
				   && !visited[nextx][nexty]){
					if(graph[nextx][nexty] == '#') continue;
						visited[nextx][nexty]= true;
						path[nextx][nexty]= f;
						qq.push({nextx, nexty});
				}
			}
		}
	};
	bfs({A.first, A.second});
	map<pair<int,int>,char> direct;
	direct[{1,0}] = 'D';
	direct[{-1,0}]= 'U';
	direct[{0,1}] = 'R';
	direct[{0,-1}] = 'L';

	if(path[B.first][B.second]==make_pair(0,0)) cout<<"NO"<<endl;
	else {
		cout<< "YES"<<endl;
		pair<int,int> temp = B;
		string s ="";
		while(temp!=A){
			s = direct[{temp.first - path[temp.first][temp.second].first
				, temp.second - path[temp.first][temp.second].second}] + s;
			temp = path[temp.first][temp.second];
		}
		cout<< s.size()<<endl;
		cout<< s<<endl;

	}


}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
