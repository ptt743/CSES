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
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	int n;  cin>> n;
	long long x; cin>> x;
	vector<long long> arr(n);
	for(int i =0;i< n;i++) cin>> arr[i];


	map<long long, vector<pair<int,int>>> mp;
	for(int i =0;i< n;i++){
		for(int j = i+1;j< n;j++){
			mp[arr[i] + arr[j]].push_back({i,j});
		}
	}

	for(int i =0;i< n;i++){
		for(int j = i+3;j< n;j++){
			long long val = x - (arr[i] + arr[j]);
			if(mp.find(val)!=mp.end()
			   && mp[val].size()!=0){
				int left = 0;
				int right = mp[val].size();
				while(left<= right){
					int mid = (left + right)/2;
					if(mp[val][mid].first>i && mp[val][mid].second<j){

						cout<< i+1<<" "<<mp[val][mid].first +1 <<" "<<mp[val][mid].second +1<<" "<<j+1<<endl; 
						return;
					}
					if(mp[val][mid].first <=i) 
						left = mid+1;
					else right = mid-1;
				}

			}

		}
	}
	
	cout<< "IMPOSSIBLE"<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
