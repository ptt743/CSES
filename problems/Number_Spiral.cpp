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
	int t; cin>> t;
	while(t--){
		int x,y;
		cin>> x >> y;
		long long maxl = max(x,y);
		long long minl = min(x,y);
		long long begin = (maxl-1)*(maxl-1);
		long long curr = 1ll + 2*(maxl-1);
		if(maxl%2==0){
			if(x>y){
				cout<< begin + (curr - y+1)<<endl;
			} else {
				cout<< begin + x <<endl;
			}
		} else {
			if(y>x){
				cout<< begin + (curr - x + 1)<<endl;
			} else {
				cout<< begin + y <<endl;
			}
		}
	}
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
