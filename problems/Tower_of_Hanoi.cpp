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
	vector<pair<char,char>> res;
	function<void(int, char, char, char)> recur=[&](int n, char a, char b, char c){
		if(n==0) {
			return;
		}
		recur(n-1, a, c, b);
		res.push_back(make_pair(a,b));
		recur(n-1, c, b, a);
	};
	recur(n,'1','3','2');
	cout<< res.size() << endl;
	for(pair<char,char> item: res) cout<< item.first <<" "<<item.second<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
