#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;
typedef pair<int,int>PII;
#define x first
#define y second
typedef long long ll;
const int N=1E5+10,M=210;



// 记忆化DFS
// class Solution {
// public:
//     int maxSumAfterPartitioning(vector<int> &arr, int k) {
//         int n = arr.size();
// 		vector<int> memory(n,-1);
// 		function<int(int)> dfs = [&](int j) { 
// 			if(j == -1) return 0;
// 			if(j == 0) return arr[j];
// 			int &maxResult = memory[j];
// 			if(maxResult != -1) return maxResult;
// 			for(int i=j, subMax=0; i>=max(0, j-k+1); i-- ){
// 				subMax = max(subMax,arr[i]);
// 				maxResult = max(maxResult, dfs(i-1) + (j-i+1)*subMax);
// 			}
// 			return maxResult;
// 		};

// 		return dfs(n-1);
//     }
// };

class Solution {
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k) {
        int n = arr.size();
		int f[501];
		memset(f,0,sizeof(f));
		// f[0]=0;
		for(int i = 1; i<=n; i++) {
			for(int j = i, subMax = 0; j >= max(1, i - (k-1)) ; j--){
				subMax = max(subMax,arr[j-1]);
				f[i]=max(f[i],f[j-1] + subMax*(i-(j-1)));
			}
		}
		return f[n];
    }
};


int main(){
	Solution solution;
	vector<int> arr ={1,15};
	cout << solution.maxSumAfterPartitioning(arr, 2)<< endl;
}