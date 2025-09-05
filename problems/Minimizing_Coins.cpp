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
	vector<int> a(n);
	for(int i =0;i<n;i++) cin>> a[i];
	vector<int> dp(x+1,1e9);
	dp[0] = 0;
	for(int i = 1;i<=x;i++){
		for(int j = 0;j< a.size();j++){
			if(i - a[j]>=0){
				dp[i] = min(dp[i], dp[i- a[j]]+1);
			}
		}
	}
	if(dp[x]==1e9){
		cout<<"-1"<<endl;
		return;
	}
	cout<< dp[x]<<endl;


}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
