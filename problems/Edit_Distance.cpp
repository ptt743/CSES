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
	string f, s;
	cin>> f >> s;
	int first   = f.size();
	int second = s.size();
	vector<vector<int>> dp(first+1, vector<int>(second+1,0));

	for(int i =0;i<=first;i++) dp[i][0] = i;
	for(int i = 0;i<=second;i++) dp[0][i] = i;

	for(int i =1;i<=first;i++){
		for(int j = 1;j<=second;j++){
			if(f[i-1]==s[j-1])
				dp[i][j] = dp[i-1][j-1];
			else {
				dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
			}
		}
	}
	cout<< dp[first][second]<<endl;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
