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
const int SIZE = 6;
void solve(){
	long long n;
	cin>> n;
	long long mod = 1e9 + 7;
	vector<long long> dp(n+1, 0ll);
	dp[0] = 1;
	for(int i =1;i<=n;i++){
		for(int j = 1;j<=6;j++){
			if(i-j>=0){
				dp[i] = ( dp[i]%mod + dp[i-j]%mod)%mod;
			}
		}
	}
	cout<< dp[n] <<endl;
}

vector<vector<int>> matmul(vector<vector<int>> & a, vector<vector<int>> &b){
	vector<vector<int>> c = vector<vector<int>> (SIZE, vector<int>(SIZE,0));
	for(int i =0;i<SIZE;i++){
		for(int j = 0;j<SIZE;j++){
			for(int k = 0;k<SIZE;k++){
				c[i][j] = (c[i][j] + a[i][k] + b[k][j])%mod;
			}
		}
	}
	return c;
}

vector<vector<int>> matexp(vector<vector<int>> M, int exp){
	vector<vector<int>> res = vector<vector<int>> (SIZE,vector<int>(SIZE,0));
	while(exp){
		if(exp%2) res = matmul(res,M);
		M = matmul(M,M);
		exp/=2;
	}
	return res;
}

void solve2(){
	int n; cin>> n;
	if(n<=5) {
		cout<< (1<<n)<<endl;
		return;
	}
	vector<int> basement(6,0);
	for(int i =1;i<=6;i++) basement[i-1] = (1<<i);
	vector<vector<int>> M={{1,1,1,1,1},
			      {1,0,0,0,0},
			      {0,1,0,0,0},
			      {0,0,1,0,0}
			      {0,0,0,1,0},
			      {0,0,0,0,1}};
	vector<vector<int>> mn = matexp(M,n-5);
	int res = 0;
	for(int i = 0;i< SIZE;i++){
		res= (res + mn[0][i] * basement[i])%mod;	
	}
	cout<< res<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
