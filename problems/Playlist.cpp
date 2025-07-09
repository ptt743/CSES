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
#include<map>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	int n; cin>> n;
	vector<long long> nums(n, 0);

	for(int i = 0;i<n;i++) cin>> nums[i];
	int left = 1, right = n;
	while(left <= right){
		int mid = ( left + right)/2;
		unordered_map<long long,int> mp;
		int l = 0;
		bool check = false;
		for(int i =0;i< n;i++){
			mp[nums[i]]++;
			if(i>= mid){
				mp[nums[l]]--;
				if(mp[nums[l]]==0) mp.erase(nums[l]);
				l++;
			}
			if(mp.size() == mid) check = true;
		}
		if( check) left = mid +1;
		else right = mid -1;
	}
	cout<< right<<endl;
}

void solve2(){
	int n; cin>> n;
	vector<long long> nums(n, 0);

	for(int i = 0;i<n;i++) cin>> nums[i];
	int left = 0;
	map<long long,int> mp;
	int result = 1;
	for(int right = 0; right< n;right++){
		mp[nums[right]]++;
		while(mp[nums[right]]>1){
			mp[nums[left]]--;
			if(mp[nums[left]]==0) mp.erase(nums[left]);
			left++;
		}
		result = max(result, right - left+1);
	}
	cout<< result<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve2();
    return 0;
}
