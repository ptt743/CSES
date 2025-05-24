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
	int maxeven = (n%2==0)?n:n-1;
	int minodd = 1;
	if( maxeven >=2 && abs(maxeven - minodd)==1){
		cout <<"NO SOLUTION"<<endl;
		return ;
	} 
	int count =2;
	while(count<=maxeven){
		cout<< count <<" ";
		count +=2;
	}
	while(minodd<=n){
		cout<< minodd <<" ";
		minodd+=2;
	}

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
