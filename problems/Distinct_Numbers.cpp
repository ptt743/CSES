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
	int n; cin>> n;
	set<int>st;
	for(int i = 0;i< n;i++){
		int temp; cin>> temp;
		st.insert(temp);
	}
	cout<< st.size() <<endl;
}

void solve2(){
	//if n <1e6
	int n; cin>> n;
	bitset<1000000> bs;
	for(int i = 0;i< n;i++){
		int t; cin>> t;
		bs[t] = 1;
	}
	cout<< bs.count()<<endl;
}
 
int main() {

    ios_base::sync_with_stdio(0); cin.tie(0);
    solve2();
    return 0;
}
