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

bool isPowerOfFive(string numS) {
    if(numS[0]=='0') return false;
    std::bitset<32> bits(numS);
    int num = bits.to_ulong();
    while (num > 1) {
        if (num % 5 != 0) {
            return false;
        }
        num /= 5;
    }
    return num == 1;
}

class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        // 11001
        // 1111101
        // 1001110001
       
        map<string,int> memory;
        function<int(string)> dfs = [&dfs,&memory](string input) { 
            if(memory.count(input))
                return memory[input];
            int &result = memory[input];
            result = 20;
            if(isPowerOfFive(input)){
                result = 1;
                return result;
            } else{
                for(int i = 1; i <input.length(); i++){
                    result = min(result,
                        dfs(input.substr(0,i))+dfs(input.substr(i,input.length()-i)));
                }
            }
            return result;
        };

        
        int result = dfs(s);
        if(result==20) return -1;
        else return result;
        
    }
};
// int main(){
// 	Solution solution;
// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,2,10,6};
// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.minimumTotalPrice(4, edges, price, trips)<< endl;
// }