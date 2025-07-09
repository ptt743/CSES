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
	int n;
	cin>> n;
	vector<long long> a(n,0);
	for(int i = 0;i< n;i++) cin>> a[i];
	for(int i = 1;i<n;i++) a[i]+=a[i-1];
	long long minVal = 0;
	long long maxRes = -1e9;
	for(int i =0;i< n;i++){
		maxRes = max(maxRes, a[i] - minVal);
		minVal = min(minVal, a[i]);
	}
	cout<< maxRes<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
