#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<cmath>
#include<deque>
#include<functional>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	int n, a, b;
	cin>> n >> a >> b;
	vector<long long> arr(n+1,0);
	for(int i =1;i<=n;i++){
		cin>> arr[i];
		arr[i] += arr[i-1];
	}
	multiset<long long> st;

	for(int i =a;i<=b; i++){
		st.insert(arr[i]); 
	}
	long long best = *st.rbegin();

	for(int i = 1;i<= n-a;i++){
		auto it = st.find(arr[i + a-1]);
		st.erase(it);
		st.insert(arr[min(n,i+b)]);
		best = max(best, *st.rbegin()- arr[i]);
	}
	cout<< best <<endl;
			
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
