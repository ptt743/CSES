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
	int n; cin>> n;
	vector<int> nums(n,0);
	for(int i =0;i< n;i++) cin>> nums[i];
	map<int,int> mp;
	int left = 0;
	long long result = 0;
	for(int right = 0;right<n;right++){
		mp[nums[right]]++;
		while(right - left +1!=mp.size()){
			mp[nums[left]]--;
			if(mp[nums[left]]==0) mp.erase(nums[left]);
			left++;
		}
		result+=(long long)(right - left+1);
	}
	cout<< result<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
