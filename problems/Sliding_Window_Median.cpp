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
	int n,k;
	cin>> n >> k;
	vector<int> arr(n,0);
	for(int i = 0;i< n;i++) cin>> arr[i];

	multiset<int> maxheap;
	multiset<int> minheap;
	int len = ( k+1)/2;
	int left = 0;
	for(int i = 0;i< n;i++){
		if(i>=k){
			if(*maxheap.rbegin()>=arr[left]){
				auto it = maxheap.find(arr[left]);
				maxheap.erase(it);
			}else {
				auto it = minheap.find(arr[left]);
				minheap.erase(it);
			}
			left++;
		}
		if(maxheap.size()<len) maxheap.insert(arr[i]);
		else minheap.insert(arr[i]);
		
		if(minheap.size()>0 && maxheap.size()>0){
			int end = *maxheap.rbegin();
			int start = *minheap.begin();
			if(end> start){
				auto it1 = maxheap.find(end);
				maxheap.erase(it1);
				maxheap.insert(start);

				auto it2 = minheap.find(start);
				minheap.erase(it2);
				minheap.insert(end);
			}
		}
		if(i>=k-1) cout<< *maxheap.rbegin()<<" ";
	}
}

void solve2(){
	int n,k;
	cin>> n >> k;
	vector<int> arr(n,0);
	for(int i =0;i< n;i++) cin>> arr[i];


}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
