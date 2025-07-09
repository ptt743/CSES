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
const int MAXN = 1005;
void solve(){
	int n;
	cin>> n;
	vector<vector<int>> matrix (n, vector<int>(n,0));
	vector<bitset<MAXN>> row(n), col(n);
	for(int i =0;i< n;i++){
		for(int j = 0; j< n;j++){
			for(int k = 0;k<= MAXN;k++){
				bool first = !row[i][k];
				bool second = !col[j][k];
				if(first && second){
					row[i][k] = 1;
					col[j][k] = 1;
					matrix[i][j] = k;
					break;
				}
			}
		}
	}
	for(int i = 0;i< n;i++){
		for(int j = 0;j< n;j++){
			cout<< matrix[i][j]<<" ";
		}
		cout<< endl;
	}

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
