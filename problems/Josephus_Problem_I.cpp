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
	int n ; cin>> n;
	deque<int> dq;
	for(int i =1;i<=n;i++) dq.push_back(i);
	while(dq.size()>1){
		int front = dq.front();
		dq.pop_front();
		dq.push_back(front);
		cout<< dq.front()<<" ";
		dq.pop_front();
	}
	cout<< dq.front()<<endl;


}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
