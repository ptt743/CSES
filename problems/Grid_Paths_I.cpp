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
	vector<string> arr(n);
	for(int i =0;i< n;i++) cin>> arr[i];
	int mod = 1e9+7; 
	vector<vector<int>> dp(n,vector<int>(n,0));
	dp[0][0]=1;
	for(int i =0;i< n;i++){
		for(int j = 0;j< n;j++){
			if(arr[i][j]=='*'){
				dp[i][j] = 0;
				continue;
			}
			if(i-1>=0) dp[i][j]= (dp[i][j] + dp[i-1][j])%mod;
			if(j-1>=0) dp[i][j]= (dp[i][j] + dp[i][j-1])%mod;
		}
	}
	cout<< dp[n-1][n-1]<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
