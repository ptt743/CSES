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
	string s; cin>> s;
	int n = s.size();
	vector<int> count(27,0);
	for(int i = 0;i< n;i++){
		count[s[i]-'A']++;
	}
	
	string result = "";
	char pre = '#';
	for(int i = 0;i< n;i++){
		int maxVal = 0;
		for(int j = 0;j< 26;j++){
			maxVal = max( maxVal, count[j]);
		}
		for(int j = 0;j<26;j++){
			if(pre!='#' && j == pre - 'A') continue;
			if(count[j]==0) continue;
			if((maxVal + maxVal -1 == n - result.size()) && count[j]!=maxVal) continue;
			pre = 'A' + j;
			count[j]--;
			result += pre;
			break;
		}
	}
	if(result.size()!=s.size()) cout<<"-1"<<endl;
	else cout<< result<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
