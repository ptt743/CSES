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
	string first, second;
 
	cin>> first >> second;
 
	long long mod = 1e9+3;
	int base = 31;
	
	int n = second.size();
 
	long long h =0l;
	for(int i =0;i< n;i++){
		h = ((h*base) + (second[i] - 'a' +1))%mod;
	}
 
	int m = first.size();
	vector<long long> prefix_hash(m+1, 0ll);
	vector<long long> power_base(m+1, 1ll);
 
	for(int i =0;i< m;i++){
		prefix_hash[i+1] = (prefix_hash[i]*base + (first[i] - 'a'+1)) % mod;
		power_base[i+1] = (power_base[i]*base)%mod;
	}
 
	function<long long(int,int)> get_hash=[&](int left, int right){
		long long hash = ((prefix_hash[right+1]  - prefix_hash[left]*power_base[right - left +1])  + mod *mod) %mod;
		return hash;
	};
	int count =0;
	for(int i =0;i< m- n+1;i++){
		if(get_hash(i, i +  n -1) == h){
			count++;	
		}
	}
	cout<< count<< endl;
 
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
