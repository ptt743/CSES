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
	long long n,k;
	long long x,a,b,c;
	cin>> n >> k;
	cin>> x >> a >> b >> c;

	vector<long long > arr(n,0);
	arr[0] = x;
	for(int i =1 ;i< n;i++) arr[i] = (a*arr[i-1]+b)%c;
	vector<long long> suffix(n,0);
	for(int i = n-1;i>=0;i--){
		if(i==n-1 || i %k == k-1) suffix[i] = arr[i];
		else suffix[i] =suffix[i+1] | arr[i];
	}
	long long prefix = 0;
	long long result = 0;
	for(int i =0;i< n;i++){
		if(i==0 || i%k == k-1){
			prefix = arr[i];
		}else prefix |= arr[i];
		if(i>=k-1) {
			long long temp = ( prefix | suffix[i - k+1]);
			result ^=temp;
		}
	}
	cout<< result <<endl;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
