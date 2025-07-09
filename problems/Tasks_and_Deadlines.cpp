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
	int n;
	cin>> n;
	vector<pair<long long, long long>> dl;
	for(int i =0;i< n;i++){
		long long a,b;
		cin>> a >> b;
		dl.push_back({a,b});
	}
	sort(dl.begin() , dl.end());
	long long t =0;
	long long reward = 0;
	for(int i =0;i< n;i++){
		t+=dl[i].first;
		reward+= dl[i].second - t;
	}
	cout<< reward<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
