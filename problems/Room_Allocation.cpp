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
struct node{
	int time;
	int id;
	int val;
};
void solve(){
	int n;
	cin>> n;
	vector<node> arr;
	set<int> st;
	int count  =0;
	unordered_map<int,int> mp;
	for(int i =0;i< n;i++){
		int a, b;
		cin>> a >> b;
		arr.push_back({a,i,1});
		arr.push_back({b,i,-1});
	}
	function<bool(node&,node&)> option=[&](node& a, node&b){
		return a.time< b.time || (a.time == b.time && a.val > b.val);
	};
	sort(arr.begin(), arr.end(), option);
	for(int i =0;i< arr.size();i++){
		if(arr[i].val==1){
			if(st.empty()){
				count++;
				mp[arr[i].id] = count;
			} else {
				mp[arr[i].id] = *st.begin();
				st.erase(st.begin());
			}
		} else {
			st.insert(mp[arr[i].id]);
		}
	}
	cout<< count<<endl;
	for(int i =0;i< n;i++) cout<< mp[i]<<" ";
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
