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
	int n, k;
	long long x,a,b,c;
	cin>> n >> k;
	cin>> x >> a >> b >> c;

	long long result = 0;
	long long total = x;
	long long suffix = x;
	long long prefix = 0;
	vector<long long> arr(n,0);
	arr[0]= x;
	
	for(int i =1;i<n;i++){
		arr[i] = (arr[i-1]*a + b)%c;
		total  ^= arr[i];
		suffix ^= arr[i];
	}
	int left = 0;
	for(int i =0;i< n;i++){
		if(i<k){
			suffix^=arr[i];
			if(i==k-1) result ^= total ^ suffix;
		} else {
			prefix^= arr[left++];
			suffix^= arr[i];
			result^= prefix ^ total ^ suffix;
		}
	}
	cout<< result <<endl;


}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
