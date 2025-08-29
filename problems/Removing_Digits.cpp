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
#include <climits>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	int n; cin>> n;
	vector<vector<bool>> dp(n+1, vector<bool>(11,false));
	vector<int> count(n+1,INT_MAX);
	count[n] = 0;

	int temp  = n;
	while(temp>0){
		int num = temp%10;
		dp[n][num]= true;
		temp = temp/10;
	}
	for(int i =n-1;i>=0;i--){
		for(int j = 1;j<=9;j++){
			int target = i + j;
			if(target<=n && dp[target][j]){
				count[i] = min(count[i], count[target]+1);
				int temp1 = i;
				while(temp1>0){
					int num = temp1%10;
					temp1/=10;
					dp[i][num] = true;
				}
			}
		}
	}
	cout<< count[0] <<endl;
	
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
