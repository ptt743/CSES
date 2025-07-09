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
	int n, a, b;
	cin>> n >> a >> b;
	vector<long long> arr(n+1,0);
	for(int i =1;i<=n;i++) cin>>> arr[i];
	for(int i =1;i<=n;i++) arr[i]+=arr[i-1];

	while(a<=b){
		int mid = (a+b)/2;
		for(int i =0;i<n-mid;i++){
			
		}
	}
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
