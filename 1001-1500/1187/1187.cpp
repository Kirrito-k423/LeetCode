#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;
typedef pair<int,int>PII;
#define x first
#define y second
typedef long long ll;
const int N=1E5+10,M=210;


class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
		int n1 = arr1.size();
		int n2 = arr2.size();
		sort(arr2.begin(), arr2.end());

		vector<vector<pair<int,int>>> f(2,vector<pair<int,int>>(0));
		f[0].push_back(make_pair(-1,0));
		int i;
		function<void(int,int,int)> pushP_1 = [&f](int I, int p, int delta=1) {
			int fpMinus1;
			auto it = lower_bound(f[(I+1)%2].begin(), f[(I+1)%2].end(),p-1,[](const pair<int,int> a, int b){
				return a.first <= b;
			});
			if(it != f[(I+1)%2].begin())
				fpMinus1 = (it-1)->second;
			else 
				fpMinus1 = INT_MAX;
			if(fpMinus1 != INT_MAX) 
				f[I].push_back(make_pair(p, min(fpMinus1+delta, (f[I].end()-1)->second )));
		};
		for(i=1; i<=n1; i++) {
			int I = i%2;
			f[I].push_back(make_pair(-1,INT_MAX));
			int j;
			for(j=0; j < n2 && arr2[j]<arr1[i-1]; j++) {
				int p = arr2[j];
				pushP_1(I,p,1);
			}
			int p = arr1[i-1];
			pushP_1(I,p,0);
			for(; j < n2 ; j++) {
				int p = arr2[j];
				if(p==arr1[i-1]) continue;
				pushP_1(I,p,1);
			}
			int tmp = (f[I].end()-1)->second;
			if (tmp==INT_MAX) return -1;
			f[(I+1)%2].clear();
		}
		return (f[(i+1)%2].end()-1)->second;
    }
};

int main(){
	Solution solution;
	vector<int> price ={0,11,6,1,4,3};
	vector<int> price2 ={5,4,11,10,1,0};
	cout << solution.makeArrayIncreasing(price, price2)<< endl;
}
