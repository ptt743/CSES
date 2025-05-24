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
	vector<int> count(26,0);
	for(int i = 0;i< n;i++) count[s[i] - 'a']++;
	vector<string> res;
	function<void(int, string&)> recur=[&](int n, string& s){
		if(n ==0 ){
			res.push_back(s);
			return ;
		}
		for(int i = 0;i< 26;i++){
			if(count[i]==0) continue;
			string temp = "";
			temp+=(char)('a' + i);
			string temps = s + temp;
			count[i]--;
			recur(n-1,temps);
			count[i]++;
		}
	};
	string temp = "";
	recur(n,temp);
	cout<< res.size()<<endl;
	for(string item : res) cout<< item <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
