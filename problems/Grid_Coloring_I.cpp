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
	int n,m;
	cin>> n >> m;
	vector<vector<int>> matrix (n, vector<int>(m,0));
	for(int i = 0;i<n;i++){
		for(int j = 0;j< m;j++){
			char tmp; cin>> tmp;
			matrix[i][j] = tmp - 'A';
		}
	}
	for(int i = 0;i< n;i++){
		for(int j = 0;j< m;j++){
			for(int k = 0;k< 4;k++){
				if(k== matrix[i][j]) continue;
				if((i>0 && k==matrix[i-1][j]) || (j>0 && k== matrix[i][j-1])) continue;
				matrix[i][j] = k;
				break;
			}
		}
	}
	for(int i = 0;i< n;i++){
		for(int j = 0;j< m;j++) cout<< (char)('A' + matrix[i][j]);
		cout<< endl;
	}


}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
