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
void solve2(){
	string s;
	string pattern;
	cin>> s >> pattern;
	
	int n = s.size();
	int m = pattern.size();
	
	int base = 31;
	long long mod = 1e9 +3;

	vector<long long> powder(n+1,1);
	for(int i=1;i<=n;i++) 
		powder[i] = (powder[i-1]*base)%mod;

	vector<long long> hashT(n+1,0);
	long long pttn = 0;
	
	for(int i =0;i<m;i++){
		pttn = (pttn*base + (pattern[i] - 'a'+1))%mod;
	}

	for(int i =1;i<=n;i++){
		hashT[i] =(hashT[i-1]*base + (s[i-1]-'a'+1))%mod;
	}

	function<long long(int,int)> getHash=[&](int x, int y){
		return (hashT[y] - hashT[x-1]* powder[y-x+1] + mod*mod)%mod;
	};
	int count = 0;
	for(int i =1;i<= n - m +1;i++){
		if(getHash(i,i+m-1)==pttn){
			count++;
		}	
	}
	cout<< count <<endl;
	

}
void solve3(){
	string s;
	string pattern;
	cin>> s >> pattern;

	int k = pattern.size();
	vector<int> lps = vector<int>(k,0);
	for(int i =1;i< k;i++){
		int j = lps[i-1];
		while(j>0 && pattern[i] != pattern[j]) j = lps[j-1];
		if(pattern[i] == pattern[j]) j++;
		lps[i] = j;
	}
	int n = s.size();
	int m = pattern.size();

	vector<int> res = vector<int>();
	int count = 0;
	for(int i = 0, j = 0; i<n;i++){
		while(j>0 && s[i]!=pattern[j]) j = lps[j-1];
		if(s[i]== pattern[j]) j++;
		if(j == m){
			count++;
			j = lps[m-1];
		}
	}

	cout<< count <<endl;

}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve3();
    return 0;
}
