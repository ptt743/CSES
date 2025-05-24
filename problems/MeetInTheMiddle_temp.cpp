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
	long long w;
	cin>> n >> w;
	vector< long long> arr(n);
	for(int i =0;i< n;i++) cin>> arr[i];
	vector<vector<long long>> dp(n,vector<long long>(n+1,0));
	dp[0][1] = arr[0];
	for(int i =0;i< n-1;i++){
		for(int j = 1;j<=n;j++){
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			if(j+1<=n && dp[i][j] + arr[i]<=w){
				dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + arr[i]);
			}
		}
	}
	long long result =0;
	for(int i =1;i<=n;i++) result = max(result, dp[n-1][i]);
	cout<< result <<endl;
	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
