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
	int n,q;
	cin>> n >> q;

	vector<long long> a(n);
	for(int i =0;i< n;i++) cin>> a[i];
	vector<long long> sg ( 4*n,0);
	function<void(int,int,int)> build=[&](int p , int l, int r){
		if(l == r){
			sg[p] = a[l];
			return;
		}
		int mid = (l + r)/2;
		build(p<<1, l, mid);
		build(p<<1|1, mid+1, r);
		sg[p]= sg[p<<1] + sg[p<<1|1];
	};

	function<long long(int,int,int,int,int)> query=[&](int p, int l, int r, int ql, int qr){
		if(l>= ql && r<= qr) return sg[p];
		if(l > qr || r < ql) return 0ll;
		int mid = (l + r)>> 1;
		return query(p<<1, l, mid, ql, qr) + query(p<<1|1, mid+1, r, ql,qr);
	};
	build(1,0, n-1);

	while(q--){
		int a,b;
		cin>> a >> b;
		a--;
		b--;
		cout<< query(1,0,n-1, a,b)<<endl;
	}
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
