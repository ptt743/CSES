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
	int n; cin>> n;
	vector<string> res;
	function<void(string, int)> rec=[&](string temp, int index){
		if(index==n) {
			res.push_back(temp);
			return;
		}
		for(int i = 0;i< 2;i++){
			string t = to_string(i);

			rec(temp+ t, index+1);
		}
	};
	rec("", 0);
	for(string item : res) cout<< item <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
