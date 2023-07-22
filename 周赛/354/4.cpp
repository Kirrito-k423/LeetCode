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

class Solution {
public:
    int longestValidSubstring(string s, vector<string>& forbidden) {
        
        int left = 0;
        int right = 0;
        int res = 0;
        unordered_set<string> forbiddenSet;
        unordered_set<string> forbiddenSetSmall;

        for (string& str : forbidden) {
            if (str.size() < 2) {
                forbiddenSetSmall.insert(str);
            } else {
                forbiddenSet.insert(str); 
            }
        }
        
        while (right < s.size()) {
            bool ok = true;
            int leave = 0;
            for (int i = right; i >= max(left,right-10); i--) {
                string sub = s.substr(i, right - i + 1);
				if (right - left + 1 < 2 && forbiddenSetSmall.count(sub) > 0) {
					// 优先判断长度小于2的子串
					ok = false;
                    leave = right - i + 1;
                    break;
				} else if (forbiddenSet.count(sub) > 0) {
					// 其他子串再在大集合中判断
					ok = false;
                    leave = right - i + 1;
                    break;
				}
            }
            
            if (ok) {
                res = max(res, right - left + 1);
                right++;
            } else {
                left = max(left + 1, right - leave);
            }
        }
        
        return res;
    }
};

// int main(){
// 	Solution solution;
// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,2,10,6};
// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.minimumTotalPrice(4, edges, price, trips)<< endl;
// }