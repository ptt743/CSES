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
const long long mod = 1e9 + 7;
void solve(){
	long long n;
	cin>> n;
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
				int temp = (a[i][k]%mod)*(b[k][j]%mod)%mod;
				c[i][j] = (c[i][j]%mod + temp%mod)%mod;
			}
		}
	}
	return c;
}

vector<vector<int>> matexp(vector<vector<int>>&M, long long exp){
	vector<vector<int>> res = vector<vector<int>> (SIZE,vector<int>(SIZE,0));
	for(int i =0;i< SIZE;i++) res[i][i] = 1;	
	while(exp){
		if(exp%2) res = matmul(res,M);
		M = matmul(M,M);
		exp/=2;
	}
	return res;
}

void solve2(){
	long long n; cin>> n;
	if(n<=5) {
		cout<< (1<<(n-1))<<endl;
		return;
	}
	vector<long long> basement={32,16,8,4,2,1};
	vector<vector<int>> M={{1,1,1,1,1,1},
			      {1,0,0,0,0,0},
			      {0,1,0,0,0,0},
			      {0,0,1,0,0,0},
			      {0,0,0,1,0,0},
			      {0,0,0,0,1,0}};
	vector<vector<int>> mn = matexp(M,n-6);
	long long res = 0;
	for(int i = 0;i< SIZE;i++){
		long long temp = (mn[0][i]%mod*basement[i]%mod)%mod;
		res= (res%mod + temp%mod)%mod;	
	}
	cout<< res<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve2();
    return 0;
}
