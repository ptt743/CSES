#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<cmath>
#include<map>
#include<functional>
#include<climits>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	int n; cin>> n;
	vector<pair<int,int>> arr;
	for(int i = 0;i< n;i++){
		int a,b;
		cin>> a >> b;
		arr.push_back(make_pair(b,a));
	}
	sort(arr.begin(), arr.end());
	int end = INT_MIN;
	int count =0;
	for(int i = 0;i< n;i++){
		if(arr[i].second>= end){
			count++;
			end = arr[i].first;
		}
	}

	cout<< count<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
