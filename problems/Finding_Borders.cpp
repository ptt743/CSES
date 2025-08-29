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
	string s;
	cin>> s;
	int n = s.size();
	function<vector<int>(string&)> prefix_function=[&]( string& s){
	    int n = s.size();
	    vector<int> pi(n);
	    for(int i = 1; i < n; i++){
		int j = pi[i-1];
		while(j > 0 && s[i] != s[j]) j = pi[j-1];
		if(s[i] == s[j]) j++;
		pi[i] = j;
	    }
	    return pi;
	};
	vector<int> pi = prefix_function(s);
	vector<int> res;
	for(int i = pi.back();i>0;i = pi[i-1]){
		res.push_back(i);
	}
	reverse(res.begin(), res.end());
	for(int item : res) cout<< item<<" ";


}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
