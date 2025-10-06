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

	long long base = 31;
	long long mod = 1e9 + 3;

	vector<long long> pow(n+1, 1);
	for(int i =1;i<=n;i++) pow[i] = (pow[i-1]*base)%mod;

	vector<long long> hashT(n+1,0), hashR(n+1,0);
	for(int i =1;i<=n;i++){
		hashT[i] = hashT[i-1] + (s[i-1] -'a' +1) * pow[i];
		hashR[i] = hashR[i-1] + (s[i-1] -'a' +1) * pow[n-i+1];
	}
	function<bool(int, int)> checkP=[&](int i, int len){
		long long hasht  = (hashT[i] - hashT[i-len] + mod)%mod;
		long long hashr  = (hashR[i] - hashR[i-len] + mod)%mod;
		hasht = (hasht * pow[n - i])%mod;
		hashr = (hashr * pow[i -len])%mod;
		if(hasht == hashr){
			return true;
		}
		return false;
	};
	function<int(int, int )> find=[&](int len, int base){
		int m = (len >=base)?((len-base)/2+1):0;
		int lo = 0, hi =m;
		while(lo<=hi){
			int mid = (lo+ hi)/2;
			int lent = base + 2*mid;
			int indexr = len + (lent+1)/2;
			cout<< "len"<<indexr<<" "<<lent<<endl;
			if(checkP(indexr, lent)){
				lo = mid+1;
			}else {
				hi = mid-1;
			}
			
		}
		return base + hi*2;

	};
	vector<int> res(n+1,1);
	for(int i =1;i<=n;i++){
		int len =  max(find(i,1), find(i,2));
		//res[i + (len-1)/2] = max(
	}
}

void solve2(){

	string s;
	cin>> s;
	int n = s.size();
	function<pair<vector<int>,vector<int>>(string&)> manacher = [&](string& s){
		int n = s.size();
		vector<int> d1(n), d2(n);
	    	for(int i=0,l=0,r=-1;i<n;++i){
			int k=1; if(i<=r) k=min(d1[l+r-i], r-i+1);
			while(i-k>=0 && i+k<n && s[i-k]==s[i+k]) ++k;
			d1[i]=k; if(i+k-1>r){ l=i-k+1; r=i+k-1; }
	    	}
	    	for(int i=0,l=0,r=-1;i<n;++i){
			int k=0; if(i<=r) k=min(d2[l+r-i+1], r-i+1);
			while(i-k-1>=0 && i+k<n && s[i-k-1]==s[i+k]) ++k;
			d2[i]=k; if(i+k-1>r){ l=i-k; r=i+k-1; }
	    	}
	    	return make_pair(d1,d2);
	};
	auto [d1,d2] = manacher(s);
    vector<int> best(n, 1);

    vector<int> endOdd(n), endEven(n);
    for(int c=0;c<n;++c) endOdd[c]  = c + d1[c] - 1;
    for(int j=0;j<n;++j) endEven[j] = j + d2[j] - 1;

    // Hàng đợi chỉ số tâm đang hiệu lực (tăng dần) → front luôn là nhỏ nhất
    deque<int> Qodd, Qeven;

    for(int e=0;e<n;++e){
        // Odd: thêm tâm c = e (odd bắt đầu tại chính c)
        if(d1[e] > 0) Qodd.push_back(e);
        while(!Qodd.empty() && endOdd[Qodd.front()] < e) Qodd.pop_front();
        if(!Qodd.empty()){
            int cmin = Qodd.front();
            best[e] = max(best[e], 2*(e - cmin) + 1);
        }

        // Even: thêm tâm j = e+1 (vì khoảng bắt đầu tại (j-1)=e)
        int j = e + 1;
        if(j < n && d2[j] > 0) Qeven.push_back(j);
        while(!Qeven.empty() && endEven[Qeven.front()] < e) Qeven.pop_front();
        if(!Qeven.empty()){
            int jmin = Qeven.front();
            best[e] = max(best[e], 2*(e - jmin + 1));
        }
    }
    for(int i =0;i< n;i++) cout<< best[i]<<" ";

}


 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    solve2();
    return 0;
}
