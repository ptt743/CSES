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
	int t;
	cin>> t;	
	vector<vector<long long>> dp(1e6+1, vector<long long>(2,0));
	while(t--){
		int n;
		cin>> n;

		int mod = 1e9 +7;
		dp[n][0] = 1;
		dp[n][1] = 1;
		for(int i = n-1;i>=1;i--){
			dp[i][1] = (2*dp[i+1][1] + dp[i+1][0])%mod;
			dp[i][0] = (4*dp[i+1][0] + dp[i+1][1])%mod;
		}
		cout<< ( dp[1][0] + dp[1][1])%mod<<endl;

	}
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
