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
	vector<long long> a(n, 0);
	for(int i = 0;i< n;i++) cin>> a[i];
	sort(a.begin(), a.end());
	vector<long long> prefix(n, 0);
	vector<long long> suffix(n, 0);

	prefix[0] = a[0];
	for(int i = 1;i< n;i++) prefix[i] = prefix[i-1] + a[i];
	suffix[n-1] = a[n-1];
	for(int i = n-2;i>=0;i--) suffix[i] = suffix[i+1] + a[i];
	long long res = 2e14+1;
	for(int i = 0;i< n;i++){
		long long left = 0, right = 0;
		if(i!=0) left = (i)*a[i] - prefix[i-1];
		if(i!=n-1) right = suffix[i+1] - (n - i -1)*a[i];
		res = min(res, left + right);
	}
	cout << res <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
