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
	vector<long long> pre (7,1);
	long long mod = 1e9 + 7;
	for(int i =1;i<=n;i++){
		long long sum = 0;
		for(int j = 1;j<=6;j++){
			if(j<= i){
				sum = (sum%mod + pre[j]%mod)%mod;
			}
		}
		for(int j = 6;j>=2;j--){
			pre[j] = pre[j-1];
		}
		pre[1] = sum;
		
	}
	cout<< pre[1]<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
