#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<cmath>
#include<map>
#include<functional>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	int n,m;
	cin>> n >> m;
	map<int,int> mp;
	for(int i = 0;i< n;i++){
		int temp; cin>> temp;
		mp[temp]++;
	}
	for(int i = 0;i<m;i++){
		int temp; cin>> temp;
		if(mp.empty()){
			cout<<"-1"<<endl;
			continue;
		}
		auto it = mp.upper_bound(temp);
		if (it!=mp.begin()){
			--it;
			cout<< it->first<<endl;
			mp[it->first]--;
			if(mp[it->first]==0) mp.erase(it->first);
		} else cout<<"-1"<<endl;
	}
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
