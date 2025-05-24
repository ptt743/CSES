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
	int n, x;
	cin >> n >> x;
	vector<long long> a(n);
	for(int i =0;i< n;i++) cin>> a[i];
	int mid = n/2;
	vector<long long> left, right;
	for(int i =0;i< mid;i++) left.push_back(a[i]);
	for(int i = mid; i< n;i++) right.push_back(a[i]);

	function<vector<long long>(vector<long long>&, int)> genSubset=[&](vector<long long>& arr, int len){
		vector<long long> result;
		for(int i = 0;i< 1<<len;i++){
			long long sum = 0;
			for(int j = 0;j< len;j++){
				if((1<<j)& i) sum += arr[j];
			}
			result.push_back(sum);
		}
		return result;
	};
	vector<long long> genl = genSubset(left, mid);
	vector<long long> genr = genSubset(right, n - mid);
	sort(genr.begin(), genr.end());
	long long result = 0;
	for(int i =0;i< genl.size();i++){
		long long key = x - genl[i];
		int indl = lower_bound(genr.begin(), genr.end(), key) - genr.begin();
		int indr = upper_bound(genr.begin(), genr.end(), key) - genr.begin();
		result += (long long)(indr - indl);
	}
	cout<< result <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
