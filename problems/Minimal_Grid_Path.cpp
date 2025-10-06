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
	int n;
	cin>> n;
	vector<string> chars(n);
	for(int i =0;i< n;i++) cin>> chars[i];

	long long mod = 1e9 + 3;
	long long base = 31;
	
	vector<vector<long long>> dp( n, vector<long long> (n, 1e9+3));

	dp[0][0] = chars[0][0] - 'A'+1;
	for(int i =0;i<n;i++){
		for(int j = 0;j< n;j++){
			if(i-1>=0){
				dp[i][j] = min(dp[i][j], ((dp[i-1][j]*base)%mod + ( chars[i][j]-'A'+1))%mod);
			}
			if(j-1>=0){
				dp[i][j] = min(dp[i][j], ((dp[i][j-1]*base)%mod + (chars[i][j]-'A'+1))%mod);
			}
		}
	}
	int i = n-1, j = n-1;
	string result = "";
	result+= chars[n-1][n-1];
	while(i>0 || j>0){
		long long up = (i-1>=0)?dp[i-1][j]:(1e9+3);
		long long left = (j -1>=0)? dp[i][j-1]:(1e9+3);
		if(up<left){
			i--;
		}	
		else j--;
		cout<< i << " "<<j <<endl;
		result+= chars[i][j];
	}
	reverse(result.begin(), result.end());
	cout<< result <<endl;


}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
