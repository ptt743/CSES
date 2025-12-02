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
	cin>> n >>k;
	vector<long long> arr(n+1,0);
	for(int i =1;i<=n;i++) cin>> arr[i];

	multiset<long long> maxheap;
	multiset<long long> minheap;
	int len = ( k+1)/2;
	int left = 1;

	vector<int> prefix(n+1,0);
	for(int i = 1;i<=n;i++){
		prefix[i] = prefix[i-1] + arr[i];
	}

	long long sumleft = 0;
	long long sumright = 0;

	for(int i = 1;i<=n;i++){
		if(i>=k+1){
			if(*maxheap.rbegin()>=arr[left]){
				auto it = maxheap.find(arr[left]);
				sumleft-= *it;
				maxheap.erase(it);
			}else {
				auto it = minheap.find(arr[left]);
				sumright -=*it;
				minheap.erase(it);
			}
			left++;
		}
		if(maxheap.size()<len) {
			maxheap.insert(arr[i]);
			sumleft+= arr[i];
		}
		else{
			minheap.insert(arr[i]);
			sumright+=arr[i];
		}
		
		if(minheap.size()>0 && maxheap.size()>0){
			long long end = *maxheap.rbegin();
			long long start = *minheap.begin();
			if(end> start){
				sumleft  = sumleft - end + start;
				auto it1 = maxheap.find(end);
				maxheap.erase(it1);
				maxheap.insert(start);
 
				sumright = sumright - start + end;
				auto it2 = minheap.find(start);
				minheap.erase(it2);
				minheap.insert(end);
			}
		}
		if(i>=k){
			long long key = *maxheap.rbegin();
			cout<< key*maxheap.size() - sumleft + sumright - key*minheap.size()<<" ";
		}
	}
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
