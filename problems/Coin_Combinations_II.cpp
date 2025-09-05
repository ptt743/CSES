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
	cin>> n >> x;
	vector<int> coins(n,0);
	for(int i =0;i< n;i++) cin>> coins[i];

	vector<int> dp(x+1,0);
	dp[0] = 1;
	int mod = 1e9+ 7;
	for(int i =0;i< n;i++){
		for(int j = 0;j<=x;j++){
			if(j - coins[i]>=0 && dp[j - coins[i]]>0)
				dp[j] = (dp[j]%mod + dp[j - coins[i]]%mod)%mod;
		}
	}
	cout<< dp[x] <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
