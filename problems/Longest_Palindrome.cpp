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
	string s;
	cin>> s;
	int n = s.size();
	string r = s;
	reverse(r.begin(), r.end());
	
	int base = 31;
	long long mod  = 1e9+3;
	vector<long long> powder(n+1, 1);
	vector<long long> hashT(n+1, 0), hashR(n+1, 0);
	for(int i =1;i<=n; i++){
		powder[i] = (powder[i-1] * base) %mod;
		hashT[i] = (hashT[i-1] * base + ( s[i-1] -'a' +1))%mod;
		hashR[i] = (hashR[i-1]* base + ( r[i-1] - 'a' +1))%mod;
	}

	function<long long( int, int, vector<long long>&)> getHash=[&](int l, int r, vector<long long>& input){
		return (input[r] - input[l-1]*powder[r-l+1]%mod + mod)%mod;
	};

	int right = n, left = 0;

	int len = 0;
	int index = 0;
	while( left <= right){
		int mid = ( left + right)/2;
		bool check = false;
		for(int i =1;i + mid -1 <= n;i++){
			int j = n - (i + mid-1) +1;
			if(getHash(i, i + mid -1, hashT) == getHash(j, j+mid - 1, hashR)){
				check = true;
				index = i;
				len = mid;
			}
			if(i + mid <=n){
				int mid2=  mid +1;
				j = n - (i + mid2-1) +1;
				if(getHash(i, i + mid2 -1, hashT) == getHash(j, j+mid2 - 1, hashR)){
					check = true;
					index = i;
					len = mid2;
				}
			}
				
		}
		if(check) left = mid+1;
		else right = mid-1;
	}
	cout<< s.substr(index-1, len)<<endl;
		
}

void solve2(){
	string s;
	cin>> s;
	int n = s.size();


}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
