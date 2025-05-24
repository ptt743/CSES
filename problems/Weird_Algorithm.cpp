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
<<<<<<< HEAD
	long long m;
	cin >> m;
	while(m!=1){
		cout<< m<<" ";
		if(m%2==0) m/=2;
		else m = 3*m+1;

	}
	cout<<"1"<<endl;

=======
	long long n; cin>>n;
	int res = 0;
	function<void(int)> bfs=[&](int u){
		queue<pair<int,int>> qq;
		qq.push(make_pair(u,1));
		set<int> visited;
		visited.insert(u);
		while(!qq.empty()){
			pair<int,int> front = qq.front();
			qq.pop();
			int v = front.first;
			int w = front.second;
			if(v==1) {
				res = w;
				return;
			}
			if(v%2==0 && visited.find(v/2)==visited.end()) qq.push(make_pair(v/2,w+1));
			if(v%2!=0 && visited.find(3*v+1)==visited.end()) qq.push(make_pair(3*v+1, w+1));
		}
	};
		bfs(n);
		cout<< res<<endl;
	
>>>>>>> refs/remotes/origin/main
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
