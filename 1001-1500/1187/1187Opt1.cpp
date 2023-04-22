#include <bits/stdc++.h> 
#include <iostream>
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

		vector<vector<int>> f(2,vector<int>(n2+2,0));
		int i;
		
		for(i=1; i<=n1; i++) {
			int I = i%2;
			int j;
			f[I][0]=INT_MAX;
			for(j=0; j < n2 && arr2[j]<arr1[i-1]; j++) {
				if(f[(I+1)%2][j]==INT_MAX)
					f[I][j+1]=INT_MAX;
				else{
					f[I][j+1]=f[(I+1)%2][j]+1;
				}
			}
			int val = f[(I+1)%2][j];
			for(; j <= n2 ; j++) {
				if(f[(I+1)%2][j]==INT_MAX)
					f[I][j+1]=val;
				else{
					f[I][j+1]=min(f[(I+1)%2][j]+1,val);
				}
			}
			int tmp = f[I][n2+1];
			if (tmp==INT_MAX) return -1;
			f[(I+1)%2].clear();
		}
		return f[(i+1)%2][n2+1];
    }
};

int main(){
	Solution solution;
	vector<int> price ={1,5,3,6,7};
	vector<int> price2 ={4,3,1};
	cout << solution.makeArrayIncreasing(price, price2)<< endl;
}
