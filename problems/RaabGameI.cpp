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
	int t; cin>> t;
	while(t--){
		int n, a, b;
		cin>> n >> a >> b;
		if((a>0 && b==0) || ( a==0 && b>0)){
			cout<<"NO"<<endl;
			continue;
		}
		if( n - a < b || n - b< a) {
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		int count = n - (a+b);
		vector<int> temp;
		for(int i = 1;i<=n;i++){
			temp.push_back(i);
		}
		cout<< endl;

		for(int i = 0;i<count;i++) cout<<temp[i]<<" ";
		for(int i = 0;i<a;i++) cout<< temp[count+ b+  i]<<" ";
		for(int i =0;i< b;i++) cout<< temp[count+i]<<" ";
		cout<< endl;

		for(int i = 0;i< n;i++) cout<< temp[i]<<" ";
		cout<<endl;
	}
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
