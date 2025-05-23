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
	vector<vector<char>> matrix(9,vector<char>(9,' '));
	for(int i = 1;i<=8;i++)
		for(int j =1; j< 8;j++)
			cin>> matrix[i][j];
	vector<bool> col(9,false);
	vector<bool> left(16, false);
	vector<bool> right(16,false);
	int count = 0;
	function<void(int)> recur=[&](int row){
		if(row==9){
			count++;
			return;
		}
		for(int i = 1;i<=8;i++){
			if(matrix[row][i] =='*') continue;
			if(col[i] || left[8 + i - row] || right[row + i -1]) continue;
			col[i] = true;
			left[8 + i - row] = true;
			right[row + i - 1] = true;
			recur(row+1);
			col[i] = false;
			left[8 + i - row] = false;
			right[row + i -1] = false;
		}
		
	};
	recur(1);
	cout<< count << endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
