#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<map>
#include<cmath>
#include<functional>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	int n;
	long long x;
	cin>> n >> x;
	vector<long long> a(n);
	for(int i =0; i<n;i++) cin>> a[i];
	map<long long,int> mp;
	long long sum =0;
	long long result = 0;
	for(int i =0;i< n;i++){
		sum+=a[i];
		if(sum==x) result++;
		result +=mp[sum - x];
		mp[sum]++;
	}
	cout<< result <<endl;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
