#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_set<char> targetSet{'a','e','i','o','u'};
    bool isCandidateString(string & target){
        // function<bool(char)> check = [](char tmp){
        //     return tmp=='a'||tmp=='e'||tmp=='i'||tmp=='o'||tmp=='u';
        // };
        return targetSet.count(target[0])&&targetSet.count(*target.rbegin());
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        //区间满足使用前缀和
        int n = words.size();
        vector<int> prefixSum;
        int count = 0;
        prefixSum.push_back(count);
        for(int i=0; i<n; i++){
            if(isCandidateString(words[i])){
                count++;
            }
            prefixSum.push_back(count);
        }
        vector<int> result;
        for(auto &query : queries){
            int &begin = query[0];
            int &end = query[1];
            result.push_back(prefixSum[end+1]-prefixSum[begin]);
        }
        return result;
    }
};


// int main(){
// 	Solution solution;
// 	vector<vector<int>> queries  = {{0,2},{1,4},{1,1}} ;
// 	// vector<vector<int>> trips = {{0,3},{2,1},{2,3}};
// 	vector<string> words  ={"aba","bcb","ece","aa","e"};
// 	solution.vowelStrings(words , queries );
// }