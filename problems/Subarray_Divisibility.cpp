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
	long long n; cin>> n;
	vector<long long> a(n,0);
	for(int i =0;i<n;i++) cin>> a[i];
	map<long long,long long> mp;
	long long result =0;
	long long sum =0;
	mp[0]=1;
	for(int i =0;i< n;i++){
		sum = sum + a[i];
		result+= mp[((sum%n)+n)%n];
		mp[((sum%n)+n)%n]++;
	}
	cout<< result <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
