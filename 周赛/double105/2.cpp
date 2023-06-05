#include <bits/stdc++.h>

using namespace std;

// struct DefaultValue {
//     using value_type = int;
//     int operator()() const {
//         return INT_MAX;
//     }
// };

class Solution {
public:
    
    int minExtraChar(string s, vector<string>& dictionary) {
        //dfs (i, j) 考虑s中前 i 个元素， 最后包含是第j个dictionary 单词，""代表不包含
        unordered_set<string> dictSet(dictionary.begin(), dictionary.end());
        // dictSet.insert("");
        int n = s.size();
        // map<pair<int, string>,int, std::less<int>, DefaultValue,std::allocator<std::pair<const pair<int, string>, int>>> memory;
        map<pair<int, string>,int> memory;
        map<pair<int, string>,int> memoryUsed;
        auto isSuffix = [](const std::string& A, const std::string& B) {
            if (A.size() < B.size()) {
                return false;  // B 长度比 A 长，不满足条件
            }
            
            // 在 A 中截取 B 长度的子字符串，与字符串 B 进行比较
            return A.compare(A.size() - B.size(), B.size(), B) == 0;
        };
        function<int(int,string)> dfs = [&dfs, &isSuffix, &s, &memoryUsed, &memory, &dictSet](int curIndex, string last){ 
            if(curIndex < 0) return 0;
            int &restS = memory[{curIndex, last}];  
            int &isUsed = memoryUsed[{curIndex, last}];  
            if(isUsed!=0) return restS;
            isUsed=1;
            restS=INT_MAX-1;
            if(last=="233"){
                for(auto it = dictSet.begin(); it != dictSet.end(); ++it) {
                    restS = min(restS, dfs(curIndex, *it));
                }
                restS = min(restS, dfs(curIndex-1, "233")+1);
            }else{
                if(isSuffix(s.substr(0,curIndex+1),last)){
                    restS = min(restS, dfs(curIndex-last.size(), "233"));
                }
            }
            return restS;  
        };

        // int restS = INT_MAX;
        // for(auto it = dictSet.begin(); it != dictSet.end(); ++it) {
        //     restS = min(restS, dfs(n-1, *it));
        // }
        return dfs(n-1,"233");
    }
};

// 太不熟练了 动态规划


int main(){
	Solution solution;
	vector<string> edges = {"hello","world"} ;
	// vector<vector<int>> trips = {{0,3},{2,1},{2,3}};
	// vector<int> price ={2,2,10,6};
	cout << solution.minExtraChar("sayhelloworld", edges)<< endl;
}