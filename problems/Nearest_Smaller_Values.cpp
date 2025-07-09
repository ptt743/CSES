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
	vector<int> arr(n,0);
	for(int i =0;i< n;i++) cin>> arr[i];
	stack<int> st;
	vector<int> result(n,0);
	for(int i =0;i< n;i++){
		while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
		if(!st.empty()) result [i]= st.top()+1;
		st.push(i);
	}
	for(int i =0;i< n;i++) cout<< result[i]<<" ";
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
