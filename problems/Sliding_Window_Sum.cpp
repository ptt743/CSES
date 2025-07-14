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
	int n,k;
	long long x,a,b,c;
	cin>> n >>k;
	cin>> x>> a >> b >> c;

	long long left = x;
	long long pre = x;
	long long sum =pre;
	long long result =0;
	if(k==1) result = sum;
	for(int i =2;i<=n;i++){
		pre = (pre*a +b)%c;
		sum+= pre;
		if(i==k) result = sum;
		if(i>k){
			sum -= left;
			result ^= sum;
			left = (left*a+b)%c;
		}

	}
	cout<< result <<endl;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
