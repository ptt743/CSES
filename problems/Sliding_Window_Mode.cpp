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
#include <climits>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	int n,k;
	cin >> n >> k;
	vector<long long> nums(n+1,0);
	for(int i =1;i<=n;i++) cin>> nums[i];
	unordered_map<long long,int> mp;
	set<pair<int,long long>> st;

	int left = 1;
	for(int i =1;i<=n;i++){
		if(mp[nums[i]]!=0)st.erase({(-1)*mp[nums[i]], nums[i]});
		mp[nums[i]]++;
		st.insert({(-1)*mp[nums[i]], nums[i]});
		if(i>=k){
			cout << st.begin()->second<<" ";
			st.erase({(-1)* mp[nums[left]],nums[left]});
			mp[nums[left]]--;
			st.insert({(-1)* mp[nums[left]],nums[left]});
			left++;
		}
	}
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
