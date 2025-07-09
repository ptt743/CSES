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
	int n,m;
	cin>> n >> m;
	vector<int> nums(n+1,0);
	for(int i = 1;i<=n;i++) cin>> nums[i]; 
	vector<int> pos(n+1,-1);
	set<pair<int,int>> st;
	for(int i =1;i<=n;i++){
		pos[nums[i]] = i;
		if( nums[i]-1>0 && pos[nums[i]-1]==-1) 
			st.insert(make_pair(nums[i]-1,nums[i]));
	}
	while(m--){
		int indexa, indexb;
		cin>> indexa >> indexb;
		int a = nums[indexa];
		int b = nums[indexb];
		swap(nums[indexa], nums[indexb]);
		swap(pos[a], pos[b]);
		if( a>1){
			if(pos[a-1]< pos[a] && st.find(make_pair(a-1,a))!=st.end())
				st.erase(make_pair(a-1,a));
			if(pos[a-1]> pos[a]) 
				st.insert(make_pair(a-1,a));
		}
		if(a<n){
			if(pos[a+1] > pos[a] && st.find(make_pair(a, a+1))!=st.end())
				st.erase(make_pair(a,a+1));
			if(pos[a+1]< pos[a])
				st.insert(make_pair(a,a+1));
		}

		if( b>1){
			if(pos[b-1]< pos[b] && st.find(make_pair(b-1,b))!=st.end())
				st.erase(make_pair(b-1,b));
			if(pos[b-1]> pos[b]) 
				st.insert(make_pair(b-1,b));
		}
		if(b<n){
			if(pos[b+1] > pos[b] && st.find(make_pair(b, b+1))!=st.end())
				st.erase(make_pair(b,b+1));
			if(pos[b+1]< pos[b])
				st.insert(make_pair(b,b+1));
		}
		cout<< st.size() +1 <<endl;
	}
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
