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
    int maximumNumberOfStringPairs(vector<string>& words) {
        set<string> Set;
        int result = 0;
        for(auto word:words){
            auto wordV =word;
            reverse(wordV.begin(),wordV.end());
            if(Set.count(wordV)){
                result++;
                Set.erase(wordV);
            }else{
                Set.insert(word);
            }
        }
        return result;
    }
};

// int main(){
// 	Solution solution;
// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,2,10,6};
// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.minimumTotalPrice(4, edges, price, trips)<< endl;
// }