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
	unsigned long long n;
	cin>> n;
	// 0 01 10 11 100 101 110 

	unsigned long long m = n+1;

	unsigned long long result = 0;
	for(int i =0 ; (1ULL<<i) <= n; i++){
		unsigned long long block = 1ULL<<(i+1);
		unsigned long long full = m/block;
		unsigned long long rem = m% block;

		result += full * (1ULL << i);

		if( rem > (1ULL << i))
			result += rem- (1ULL<<i);
	}
	cout<< result <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
