#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<cmath>
#include<deque>
#include<functional>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	long long n,k;
	cin>> n >>k;
	long long x,a,b,c;
	cin>> x >> a >> b >> c;
	
	long long left = x;
	long long pre = x;
	long long result =0;
	deque<pair<long long,int>> dq;
	dq.push_back({left, 0});

	if(k==1) result^=left;
	for(int i =1;i< n;i++){
		pre = (a*pre + b ) %c;
		while(!dq.empty() && dq.back().first> pre) dq.pop_back();
		if(!dq.empty() && dq.front().second <= i - k) dq.pop_front();
		dq.push_back({pre, i});
		if(i>=k-1){
			result^=(dq.front().first);
		}
	}
	cout<< result <<endl;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
