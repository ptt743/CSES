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
	int base = 31;
	long long mod = 1e9+3;

	vector<long long> power(n+1,1);
	vector<long long> hashT(n+1,0);
	for(int i = 1;i<=n;i++){ 
		power[i]= (power[i-1]*base)%mod;
		hashT[i] = (hashT[i-1]*base + (s[i-1]- 'a'+1))%mod;
	}
	
	function<long long(int,int)> getHash = [&](int left, int right){
		return (hashT[right] - hashT[left-1]* power[right - left + 1] + mod*mod)%mod;
	};
	vector<int> res;

	for(int i = 1;i<=n;i++){
		int curr = 1;
		bool check = true;
		while( curr <=n){
			int len = min(i, n - curr+1);
			check &t (getHash(1,len) == getHash(curr, curr + len - 1));
			curr +=len;
		}
		if(check) res.push_back(i);
	}
	for(int item : res) cout<< item<<" ";
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
