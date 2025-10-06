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
	int n, m;
	cin>> n >> m;
	vector<int>a(n+1,0);
	vector<int>b(m+1,0);

	for(int i = 1;i<=n;i++) cin>> a[i];
	for(int i = 1;i<=m;i++) cin>> b[i];
	vector<vector<int>> dp(n+1, vector<int>(m+1,0));

	for(int i =1;i<=n;i++)
		for(int j = 1;j<=m;j++){
			if(a[i]==b[j]) dp[i][j] = max(dp[i][j], 1 + dp[i-1][j-1]);
			else dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
		}
	int i = n, j = m;
	vector<int> result;
	while( i>0 && j >0){
		if(a[i]==b[j]){
			result.push_back(a[i]);
			i--;
			j--;
		} else if(dp[i-1][j]>dp[i][j-1]) i--;
		else j--;
	}
	reverse(result.begin(), result.end());
	cout<< dp[n][m]<<endl;
	for(int i =0;i< result.size();i++) cout<< result[i]<<" ";
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
