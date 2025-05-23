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
#include<bitset>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	int n ; cin>> n;
	vector<long long> p (n,0);
	long long total = 0;
	for(int i = 0; i< n;i++){
		cin>> p[i];
		total +=p[i];
	}
	long long result = 2e10 +1;
	for( long long mask = 0; mask < (1<<n) ; mask++){
		long long firstHalf = 0;
		for(int i = 0;i< n;i++){
			if(mask & (1<<i)){
				firstHalf+= p[i];
			}
		}
		result = min(result, abs(2ll*firstHalf - total));
	}
	cout<< result <<endl;
	
}

void solve2(){
	int n ; cin>> n;
	vector<long long> p(n,0);
	long long total = 0;
	for(int i = 0;i< n;i++){
		cin>> p[i];
		total+= p[i];
	}
	int nl = n/2;
	int nr = n - nl;
	
	vector<long long> left, right;
	for(long long mask = 0;mask< (1<<nl);mask++){
		long long sum =0;
		for(int i = 0;i< nl;i++){
			if(mask & (1ll<<i)){
				sum+=p[i];
			}
		}
		left.push_back(sum);
	}
	
	for(long long mask = 0; mask< (1<<nr);mask++){
		long long sum = 0;
		for(int i = 0;i< nr;i++){
			if(mask & (1ll<<i)){
				sum +=p[nl + i];
			}
		}
		right.push_back(sum);
	}
	sort(right.begin(), right.end());
	
	// total - 2*(left + right) min => right ~ total/2 - left
	long long result = 2e10+1;
	for(long long item : left){
		long long target = total/2ll - item;
			
		auto it = lower_bound(right.begin(), right.end(), target);
		
		if(it!=right.end()){
			result = min(result, llabs(total - 2*(item + *it)));
		}
		if(it!=right.begin()){
			it--;
			result = min(result, abs(total - 2*(item + *it)));
		}
		
	}
	

	cout<< result <<endl;
	
}

void solve3(){
	int n ; cin>> n;
	vector< long long> p(n,0);
	long long total = 0;
	for(int i = 0;i< n;i++){
		cin>> p[i];
		total += p[i];
	}

	const int MAX_VALUE = 200000;
	bitset<MAX_VALUE +1> bs;
	bs[0] = 1;
	for(int i =0;i< n;i++){
		bs = bs | (bs <<p[i]);
	}
	long long res = 2e10 + 1;
	for(long long temp = 0;temp <= total/2; temp++){
		if(bs[temp]){
			res = abs(total - 2*temp);
		}
	}
	cout<< res<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve3();
    return 0;
}
