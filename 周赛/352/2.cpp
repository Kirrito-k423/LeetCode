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

bool is_prime(int n) {
  for (int i = 2; i * i <= n; ++i)
    if (n % i == 0)
      return false;
  return n >= 2; // 1 不是质数
}

class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> result;
        for(int i = 2; i <= n/2 ;i++){
            if(is_prime(i) && is_prime(n-i)){
                vector<int> tmp = {i,n-i};
                result.push_back(tmp);
            }
        }
        return result;
    }
};


int main(){
	Solution solution;
	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
	vector<int> price ={2,2,10,6};
	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
	solution.findPrimePairs(10);
}