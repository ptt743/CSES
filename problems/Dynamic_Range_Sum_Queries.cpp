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

	vector<long long> nums(n);
	for(int i =0;i< n;i++) cin>> nums[i];
	vector<long long> sg(4*n,0);
	function<void(int,int,int)> build = [&](int p , int l , int r){
		if(l == r){
			sg[p] = nums[l];
			return;
		}
		int mid = ( l + r)>>1;
		build(p<<1, l, mid);
		builf(p<<1|1, mid+1, r);
		sg[p] = sp[p<<1] + sg[p<<1|1];
	};

	function<long long(int,int ,int, int ,int)> query =[&](int p , int l , int r, int ql, int qr){
		if( l>= ql && r <= qr) return seg[q];
		if(l > qr || r < ql) return 0ll;
		int mid = (l + r)/2;
		return query(p<<1, l, mid, ql,qr) + query(p<<1|1, mid+1, r, ql,qr);
	};
	function<void(int,int ,int ,int)> edit = [&](int p, int l, int r, int index){
		if(l == r){
			sg[p] = nums[index];
			return;
		}
		int mid = (l + r)>>1;
		if(index < mid){
			edit(p<<1, l, mid, index);
		} else{
			edit(p<<1|1, mid+1, index);
		}
		sg[p] = sg[p<<1] + sg[p<<1|1];
	};
	build(1,0, n-1);
	while(q--){
		int t; cin>> t;
		if(t==1){
			int index;
			long long val;
			cin>> index >> val;
			index--;
			nums[index] = val;
			edit(1, 0,n-1, index);
		} else {
			int a, b;
			cin>> a >> b;
			a--; b--;
			cout<< query(1,0,n-1, a,n)<<endl;
		}
	}
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
