#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<map>
#include<cmath>
#include<functional>
#define ll long long

using namespace std;
//*****taipt*****//
/*
*/
void solve(){
	string s;
	cin>> s;
	int n = s.size();

	int i = 0, j = 1, k = 0;
	while(i< n && j < n && k< n){
		char a = s[(i+k)%n];
		char b = s[(j+k)%n];
		if(a==b) {
			k++;
		} else if ( a>b){
			i = i +k +1;
			if(i ==j) i++;
			k = 0;
		} else {
			j = j + k +1;
			if(i == j) j++;
			k = 0;
		}
	}
	int index = min(i,j);
	int count = 0;
	string result = "";
	while(count< n){
		result += (s[index%n]);
		index++;
		count++;
	}
	cout<< result<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
