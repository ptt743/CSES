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
		long long x,y;
		cin>> x >> y;
		if((2*y -x)%3!=0){
			cout<<"NO"<<endl;
			continue;
		}
		long long a = (2ll*y -x)/3ll;
		long long b = y - 2*a;
		if( a>=0 && b >=0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
