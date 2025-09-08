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
	vector<int> h(n+1,0);
	vector<int> s(n+1,0);
	for(int i =1;i<=n;i++) cin>> h[i];
	for(int i =1;i<=n;i++) cin>> s[i];

	vector<vector<int>> dp(n+1,vector<int>(x+1,0));
	for(int i =1;i<=n;i++){
		for(int j = 1;j<=x;j++){
			dp[i][j] = max(dp[i-1][j], dp[i][j]);
			if(j - h[i] >=0){
				dp[i][j] = max( dp[i-1][j- h[i]] + s[i], dp[i][j]);
			}
		}
	}
	cout<< dp[n][x]<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
