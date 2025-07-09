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
struct node{
	int x;
	int y;
	int len;
};
void solve(){
	int n; cin>> n;
	vector<vector<int>> grip(n,vector<int>(n,0));
	vector<vector<bool>> visited(n, vector<bool>(n,false));
	vector<int> dx = {2,1,-1,-2, -1,-2, 2,1};
	vector<int> dy = {1,2,2,1, -2, -1, -1,-2};
	function<void(int,int)> bfs = [&](int x,int y){
		queue<node> qq;
		qq.push({x,y,0});
		visited[x][y] = true;
		while(!qq.empty()){
			node top = qq.front();
			qq.pop();
			for(int i = 0;i< 8;i++){
				int tmpx = top.x + dx[i];
				int tmpy = top.y + dy[i];
				int templen = top.len +1;
				if( tmpx >=0 && tmpx< n 
				&&  tmpy>=0 && tmpy<n
				&& visited[tmpx][tmpy]==false){
					visited[tmpx][tmpy] = true;
					grip[tmpx][tmpy] = templen;
					qq.push({tmpx, tmpy, templen});
				}
			}

		}
	};
	bfs(0,0);
	for(int i = 0;i<n;i++){
		for(int j = 0;j< n;j++){
			cout<< grip[i][j]<<" ";
		}
		cout<<endl;
	}
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
