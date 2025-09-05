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
	vector<uint32_t> arr(n,0);
	for(int i =0;i< n;i++) cin>> arr[i];
	struct node{
		int next[2]{-1,-1};
	};

	vector<node> trie(1);

	function<void(uint32_t)> insert=[&](uint32_t x){
		int u = 0;
		for(int b = 31;b >=0;--b){
			int bit = (x>>b)&1;
			if(trie[u].next[bit]==-1){
				trie[u].next[bit] = (int)trie.size();
				trie.push_back(node());
			}
			u = trie[u].next[bit];
		}
	};

	function<uint32_t(uint32_t)> queryMax = [&](uint32_t x){
		int u = 0;
		uint32_t best = 0;
		for(int b = 31;b>=0;--b){
			int bit  = (x>>b) & 1;
			int want = bit^1;
			if(trie[u].next[want]!=-1){
				best |= (1u << b);
				u = trie[u].next[want];
			} else {
				u = trie[u].next[bit];
			}
		}
		return best;
	};
	uint32_t pref = 0;
	uint32_t ans = 0;
	insert(0);
	for(int item : arr){
		pref ^= (uint32_t)item;
		ans = max(ans, queryMax(pref));
		insert(pref);
	}
	cout<< ans <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
