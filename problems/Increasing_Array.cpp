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
	long long n; cin>> n;
	vector<long long> a(n);
	for(int i =0;i< n;i++) cin>> a[i];
	long long result = 0;
	for(int i = 1;i<n;i++){
		if(a[i]<a[i-1]){
			long long add = a[i-1] - a[i];
			result += add;
			a[i] += add;
		}
	}
	cout<< result <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
