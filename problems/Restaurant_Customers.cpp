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
	int n; cin>> n;
	vector<pair<int,int>> temp;
	for(int i = 0;i< n;i++){
		int a,b;
		cin>> a >> b;
		temp.push_back(make_pair(a,1));
		temp.push_back(make_pair(b,-1));
	}
	sort(temp.begin(), temp.end());
	int maxVal = 0;
	int tempVal = 0;
	for(int i = 0;i< temp.size();i++){
		tempVal+=temp[i].second;
		maxVal = max(maxVal, tempVal);
	}
	cout<< maxVal<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
