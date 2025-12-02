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
	int n, k;
	cin>> n >> k;
	vector<int> nums(n);
	for(int i =0;i< n;i++) cin>> nums[i];
	int curr = 0;
	set<int> st;
	while(curr<=k) st.insert(curr), curr++;

	map<int,int> mp;
	int left = 0;
	for(int i =0;i< n;i++){
		mp[nums[i]]++;
		auto it = st.find(nums[i]);
		if(it!=st.end()) st.erase(it);
		if(i>=k-1){	
			cout<< *st.begin()<<" ";
			mp[nums[left]]--;
			if(mp[nums[left]]==0) st.insert(nums[left]);
			left++;
		}
		
	}
	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
