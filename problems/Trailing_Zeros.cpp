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
 - factorial need to be plitted to prime elements
 - we can notice that 2 and 5 is two main prime elements to product 10 which form the trailing zeros of factorial
 - so find number of 2 and number of 5 is solution.
 - but we have 1<= n <= 1e9 ( TO LARGE)
   * the numbers divisible by 5 are evenly spaced by 5 units => count5 = last number / 5 
   * the numbers divisible by 25 are evenly spaced by 25 units => count25 = last number / 25
   => sum(i: 1->k)([n/5^k]) (5^k<=n)
*/
void solve(){
	int n; cin>> n;
	int result = 0;
	int temp = 5;
	while(n>=temp){
		result += n/temp;
		temp*=5;
	}
	cout<< result <<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
