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
	vector<int> a(n);
	for(int i = 0;i< n;i++) cin>> a[i];
	multiset<int> st;
	for(int i = 0;i< n;i++){
		auto it = st.upper_bound(a[i]);
		if(it!=st.end()) st.erase(it);
		st.insert(a[i]);
	}
	cout<< st.size()<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
