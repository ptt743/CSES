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
	int n;
	long long x;
	cin>> n >> x;
	vector<long long> a(n,0);
	for(int i =0;i< n;i++) cin>> a[i];
	vector<pair<long long,int>> arr;
	for(int i =0;i< n;i++) arr.push_back({a[i],i});
	sort(arr.begin(), arr.end());
	for(int i =0;i< n-2;i++){
		long long val = x - arr[i].first;
		int left = i+1, right = n-1;
		while(left<right){
			long long sum = arr[left].first + arr[right].first;
			if(sum> val) right--;
			else if(sum<val) left++;
			else {
				vector<int> result ={arr[i].second,arr[left].second,arr[right].second};
				sort(result.begin(), result.end());
				for(int item: result) cout<< item+1<<" ";
				cout<<endl;
				return;
			}

		}
	}
	cout<<"IMPOSSIBLE"<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
