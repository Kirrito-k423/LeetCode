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
		vector<unordered_map<int,int>> memory(n1);
		function<int(int,int)> dfs = [&](int i, int j) {
			if(i < 0) return 0;
			if(memory[i].count(j)) return memory[i][j];

			int &res = memory[i][j];
			res = INT_MAX;
			if(j > arr1[i]){
				res = min(res, dfs(i-1, arr1[i]));
			}
			vector<int>::iterator it = lower_bound(arr2.begin(), arr2.end(), j);
			if(it != arr2.begin()){
				int subDfs = dfs(i-1, *(it-1));
				if(subDfs != INT_MAX)
					res = min(res, subDfs+1);
			}
			return res;
		};
		int result = dfs(n1-1,INT_MAX);
		if(result != INT_MAX)
			return result;
		else
			return -1;
    }
};

// int main(){
// 	Solution solution;
// 	vector<int> price ={0,11,6,1,4,3};
// 	vector<int> price2 ={5,4,11,10,1,0};
// 	cout << solution.makeArrayIncreasing(price, price2)<< endl;
// }
