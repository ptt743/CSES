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
	int n; cin>> n;
	vector<int> nums(n,0);
	for(int i =0;i< n;i++) cin>> nums[i];

	unordered_map<int,int> mp;
	vector<vector<int>> records;
	int count = 1;
	for(int i = 0;i< n;i++){
		if(mp[nums[i]-1]!=0){
			mp[nums[i]] = mp[nums[i-1]];
		}else {
			mp[nums[i]] = count++;
		}
	}
	cout<< count-1<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
