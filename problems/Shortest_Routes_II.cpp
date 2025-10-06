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
	int n,m,q;
	cin>> n >> m >> q;
	long long INF = 4e18;
	long long NEG_INF = -4e18;
	vector<vector<long long>> dist(n+1, vector<long long>(n+1, INF));

	for(int i =1;i<=n;i++) dist[i][i] = 0;

	for(int i =0;i< m;i++){
		int a,b;
		long long c;
		cin>> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
		dist[b][a] = min(dist[b][a], c);
	}
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			if(dist[i][k] ==INF) continue;
			for(int j = 1; j<=n;j++){
				if(dist[k][j]==INF) continue;
				long long temp = dist[i][k] + dist[k][j];
				if(temp < dist[i][j]) dist[i][j] = temp;
			}
		}
	}
	for(int k = 1;k<=n;k++){
		if(dist[k][k]<0){
			for(int i = 1;i<=n;j++){
				if(dist[i][k]== INF) continue;
				for(int j = 1;j<=n;j++){
					if(dist[k][j] ==INF) continue;
					dist[i][j] = NEG_INF;
				}
			}
		}
	}
	while(q--){
		int a,b;
		cin>> a >> b;
		cout<<(dist[a][b]==INF?-1:dist[a][b])<<endl;
	}
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
