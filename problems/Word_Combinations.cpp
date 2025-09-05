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
	int k;
	int mod = 1e9+7;
	vector<string> arr;
	int n = s.size();
	cin>> k;
	while(k--){
		string t; cin>> t;
		arr.push_back(t);
	}

	struct trie{
		vector<int> next;
		int end = 0;
		trie() {
			next = vector<int>(26,-1);
		}
	};
	vector<trie> nodes;
	int root = 0;
	nodes.emplace_back();

	function<void(string)> insert=[&](string s){
		int u = root;
		for(char item : s){
			int c = item - 'a';
			if(nodes[u].next[c]==-1){
				nodes[u].next[c] = nodes.size();
				nodes.emplace_back();
			}
			u = nodes[u].next[c];
		}
		nodes[u].end++;
	};

	for(string word: arr){
		insert(word);
	}

	function<int(int, int)> dfs = [&](int index, int u){
		int c = s[index] - 'a';
		if(nodes[u].next[c]==-1) return 0;
		int count  =0;
		if(nodes[nodes[u].next[c]].end!=-1){
			if(index== n-1) return 1;
			else{
				count+= dfs(index+1, 0);
				count%=mod;
			}
		}
		count+= dfs(index+1, nodes[u].next[c]);
		count%=mod;
		return count;
	};
	vector<int> dp(n+1,0);
	dp[0] = 1;
	for(int i = 0;i< n;i++){
		if(dp[i]==0) continue;
		int u = 0;
		for(int j = i; j< n;j++){
			int c= s[j] - 'a';
			if(nodes[u].next[c]==-1) break;
			u = nodes[u].next[c];
			if(nodes[u].end){
				dp[j+1] = ( dp[j+1] + dp[i])%mod;
			}
		}
	}	

	cout<< dp[n]<<endl;


}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
