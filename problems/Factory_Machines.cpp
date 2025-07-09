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
	long long t;
	cin>> n >> t;
	vector<long long> arr(n,0);
	for(int i =0;i< n;i++) cin>> arr[i];
	sort(arr.begin(), arr.end());
	long long left =0, right = arr[0]*t;
	while(left <= right){
		long long mid = (left + right)/2;
		long long count  =0;
		for(int i =0;i< n;i++){
			count +=mid/arr[i];
		}
		if(count>=t) right = mid-1;
		else left = mid+1;
	}
	cout<< left <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
