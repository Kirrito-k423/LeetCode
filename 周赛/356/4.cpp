#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;
typedef pair<int,int>PII;
const int MOD = 1e9 + 7;
const int INF = 2e9;
// #define x first
// #define y second
typedef long long ll;
const int N=1E5+10,M=210;

int kinds[110][11];
int init = [](){
	for(int i=0; i<=9;i++){
		kinds[0][i]=1;
	}
	for(int i=1; i<110; i++){
		kinds[i][0] = kinds[i-1][1];
		for(int j=1; j<=8; j++){
			kinds[i][j] = (kinds[i-1][j-1]+kinds[i-1][j+1])%MOD;
		}
		kinds[i][9] = kinds[i-1][8];
	}
}();
class Solution {
public:
	ll count(string &input, int index){
		ll result = 0;
		// deal with first char
		char first_char = input[index];
		int length = input.size();
		for(int i=0; i<int(first_char);i++){
			result = (result + kinds[length-1-index][i])%MOD;
		}
		// how to deal with the ceil number?

	}
    int countSteppingNumbers(string low, string high) {
        //数据范围过大，遍历区间不行
		//数字字符串规律
		// low = abc ~ ab(c+1) + a(b+1)? + (a+)??
		// 分情况讨乱的做法，可行吗？
		int low_n = low.size();
		int high_n = high.size();
		int result = 0;
		if(high_n>low_n){
			result = count(high,0) - count(low,0);
		}else{
			assert(high_n==low_n);
			int prefix_same = 0;
			char pre_value = high[0];
			if(low[0]==high[0]){
				prefix_same++;
			}else{
				for(int i=1; i<high_n; i++){
					if(low[i]==high[i]){
						prefix_same++;
						if(int(low[i])-int(pre_value)==1 ||int(low[i])-int(pre_value)==-1){
							pre_value=low[i];
						}else{
							return 0;
						}
					}else{
						break;
					}
				}
			}
			
		}
    }
};

// int main(){
// 	Solution solution;
// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,2,10,6};
// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.minimumTotalPrice(4, edges, price, trips)<< endl;
// }