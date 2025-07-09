#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<cmath>
#include<map>
#include<functional>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	long long mod = 1e9 + 7;
	int n; cin>> n;
	vector<long long> arr(n);
	vector<long long> power2(n+1,1);
	for(int i =1;i<=n;i++){
		power2[i] = ((power2[i-1]%mod) * (2ll%mod))%mod;
	}
	for(int i =0;i< n;i++) cin>> arr[i];
	map<int,int> mp;
	int left =0;
	long long result = 0;
	for(int i =0;i< n;i++){
		mp[arr[i]]++;
		while(mp.size()< (i - left +1)){
			mp[arr[left]]--;
			if(mp[arr[left]]==0) mp.erase(arr[left]);
			left++;
		}
		cout<< i - left +1<<endl;
		result = (result%mod + (power2[i - left+1]-1 - i + left)%mod)%mod;
	}
	cout<< result<<endl;


}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
