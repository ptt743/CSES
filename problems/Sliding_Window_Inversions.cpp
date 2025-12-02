#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<map>
#include<cmath>
#include<functional>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	int n,k;
	cin>> n >>k;

	vector<int> arr(n,0);
	for(int i =0;i< n;i++) cin>> arr[i];
	unordered_map<int,int> mp;
	multiset<int> st;
	int count = 0;
	int left = 0;
	for(int i = 0;i< n;i++){
		if(i>=k){
			auto it = st.find(arr[left]);
			st.erase(it);
			count-= distance(st.begin(),st.lower_bound(arr[left]));
			left++;
		}
		count+= distance(st.upper_bound(arr[i]), st.end()); 
		st.insert(arr[i]);
		if(i>=k-1)cout<< count<<" ";
	}
	cout<< endl;
}

void solve2(){
	struct fenwick{
		int m;
		vector<int> bit;

		fenwick(int len){
			m= len;
			bit = vector<int>(m+1,0);
		}

		void add(int i, int delta){
			for(;i<=m;i+=i&-i) bit[i]+=delta;
		}

		int sumPrefix(int i){
			int s = 0;
			for(;i>0;i-=(i&-i)) s+= bit[i];
			return s;
		}
	};
	int n,k;
	cin>> n >>k;
	vector<int> a(n,0);
	for(int i = 0;i< n;i++) cin>> a[i];

	vector<int> comp = a;
	sort(comp.begin(), comp.end());

	comp.erase(unique(comp.begin(), comp.end()), comp.end());
    	auto idxOf = [&](int x) {
        	return int(lower_bound(comp.begin(), comp.end(), x) - comp.begin()) + 1; // 1-indexed
    	};
	int m = comp.size();

	fenwick ft(m);

	long long inv = 0;
	int left = 0;
	long long sz = 0;

	auto addRight = [&](int val) {
        	int id = idxOf(val);
        	long long leq = ft.sumPrefix(id);
        	inv += (long long)sz - leq;
        	ft.add(id, +1);
        	++sz;
	};
	auto removeLeft = [&](int val) {
		int id = idxOf(val);
		long long less = ft.sumPrefix(id - 1);
		inv -= less;
		ft.add(id, -1);
		--sz;
	};
	for (int i = 0; i < n; ++i) {
        	if (sz == k) {              // cửa sổ đủ, bỏ phần tử trái trước
            		removeLeft(a[left]);
            		++left;
        	}
        	addRight(a[i]);             // thêm phần tử phải

        	if (sz == k) {
            	cout << inv << " ";
        	}
    	}

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve2();
    return 0;
}
