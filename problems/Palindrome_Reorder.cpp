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
	string s;
	cin>> s;
	int n = s.size();
	vector<int> count(26,0);
	for(int i = 0;i< n;i++) count[s[i]-'A']++;

	int countOdd = 0;
	char charOdd = 'a';
	for(int i = 0;i< 26;i++) 
		if(count[i]%2!=0){
			charOdd = 'A' + i;
			countOdd++;
		}
	if(countOdd>=2) {
		cout<<"NO SOLUTION"<<endl;
		return;
	}
	string res ="";
	for(int i = 0;i< 26;i++){
		int nums = count[i]/2;
		res += string(nums, 'A' + i);
	}
	string tmp = res;
	reverse(tmp.begin(), tmp.end());
	res = res;
	if(charOdd!='a') res += charOdd;
	res +=tmp;
	cout<< res<<endl;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
