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
	int n,m;
	cin>>n >> m;

	vector<int> arr(n+1);
	for(int i =1;i<=n;i++) cin>> arr[i];
	vector<int> step = {-1,0,1};
	vector<long long> pre = vector<long long>(m+1,0);
	if(arr[1]==0) pre = vector<long long>(m+1,1);
	else pre[arr[1]] = 1;
	int mod = 1e9+7;
	for(int i = 2;i<=n;i++){
		vector<long long> curr = vector<long long>(m+1,0);
		if(arr[i]!=0){
			int u = arr[i];
			for(int item : step){
				if((u + item) >=1 && (u + item) <=m){
					curr[u] = ( curr[u] + pre[u +item])%mod;
				}
			}
		} else {
			for(int u = 1;u<=m;u++){
				for(int item: step){
					if((u +item) >=1 && (u + item) <=m){
						curr[u] = (curr[u] + pre[u+ item])%mod;
					}
				}
			}
		}
		pre = curr;
	}
	long long count = 0;
	for(int i =1;i<=m;i++) count= ( count + pre[i]) %mod;
	cout<< count<<endl;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
