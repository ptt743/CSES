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
	long long n,k;
	cin>> n >>k;
	long long x,a,b,c;
	cin>> x >> a >> b >> c;
	
	long long left = x;
	long long pre = x;
	long long result =0;
	multiset<long long> st;
	st.insert(left);
	if(k==1) result^=left;
	for(int i =1;i< n;i++){
		pre = (a*pre + b ) %c;
		st.insert(pre);
		if(i==k-1) result^=*(st.begin());
		if(i>=k){
			auto it = st.find(left);
			st.erase(it);
			left = (left*a + b)%c;
			result^= *(st.begin());
		}
	}
	cout<< result <<endl;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
