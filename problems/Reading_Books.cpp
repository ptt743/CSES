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
	vector<long long> arr(n);
	for(int i =0;i< n;i++) cin>> arr[i];
	sort(arr.begin(), arr.end());
	long long maxVal = 0;
	long long sum = 0;
	for(int i =0;i< n;i++){
		maxVal = max(maxVal, arr[i]);
		sum+= arr[i];
	}

	if(maxVal > sum- maxVal) cout<< 2* maxVal<<endl;
	else cout<< sum<<endl;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
