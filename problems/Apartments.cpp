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
	int n, m,k;
	cin>> n >> m >> k;

	vector<int> a(n, 0);
	multiset<int> st;
	for(int i = 0;i< n;i++) cin>> a[i];
	for(int i = 0;i< m;i++){
		int t; cin>> t;
		st.insert(t);
	}
	sort(a.begin(), a.end());
	int count = 0;
	for(int i = 0;i< n;i++){
		auto it = st.lower_bound(a[i] - k);
		if(it != st.end() && *it<= a[i] + k){
			count++;
			st.erase(it);
		}
	}
	cout<< count <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
