#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<map>
#include<cmath>
#include<functional>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	int n,m;
	cin>> n >> m;
	string s; cin>> s;
	string r = s;
	long long base = 31;
	long long mod = 1e9 +3;
	reverse(r.begin(),r.end());

	struct fenwick{
		int n;
		vector<long long> bit;
		fenwick(int len){
			n = len;
			bit = vector<long long>( len+1,0);
		}

		void add(int idx, long long delta) {
			for (; idx <= n; idx += idx & -idx) bit[idx] += delta;
		}

		long long sum(int idx) const {
			long long res = 0;
			for (; idx > 0; idx -= idx & -idx) res += bit[idx];
			return res;
		}
		long long rangeSum(int l, int r) const {
			if (l > r) return 0;
			return sum(r) - sum(l-1);
		}	

	};
	vector<long long> powder(n+1, 1);
	vector<long long> hashS(n+1, 0), hashR(n+1,0);
	for(int i =1;i<=n;i++){
		powder[i] = (powder[i-1]*base)%mod;
		hashS[i] = (hashS[i-1]*base + (s[i-1]-'a' +1))%mod;
		hashR[i] =  (hashR[i-1]*base + (r[i-1]-'a' +1))%mod;
	}


	


	while(m--){
		int type;
		cin>> type;
		if(type==1){
			int k,char x;
			cin>> k >> x;
		} else{
			int a,b;
			cin>> a >> b;


		}
	}
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
