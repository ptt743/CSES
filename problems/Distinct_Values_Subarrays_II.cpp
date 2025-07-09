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
	int n,k; cin>> n >> k;
	vector<int> arr(n);
	for(int i =0;i< n;i++) cin>> arr[i];
	map<int,int> mp;
	int left = 0;
	long long result =0;
	long long count =0;
	for(int i =0;i< n;i++){
		mp[arr[i]]++;
		count++;
		while(left<n && mp.size()>k){
			mp[arr[left]]--;
			if(mp[arr[left]]==0) mp.erase(arr[left]);
			left++;
			count--;
		}
		result+=count;
	}
	cout<< result <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
