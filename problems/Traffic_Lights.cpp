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
	int n,k; cin>> n >> k;
	set<int> st;
	multiset<int> dis;
	st.insert(0);
	st.insert(n);
	dis.insert(n);
	for(int i = 0;i< k;i++){
		int a; cin>> a;
		auto it = st.lower_bound(a);
		int right = *it;
		it--;
		int left = *it;
		st.insert(a);
		int distance = right - left;
		auto it2 = dis.find(distance);
		dis.erase(it2);
		dis.insert(a- left);
		dis.insert(right - a);
		cout<< *dis.rbegin()<<" ";
	}

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
