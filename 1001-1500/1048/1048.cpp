
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        //记忆化搜索
        //dfs(i), 返回第i个元素结尾的最长可能长度

        int n = words.size();
        int memory[1000];
        fill(memory,memory+n,-1);
        sort(words.begin(),words.end(),[](const string& a,const string& b){
            return a.size() < b.size();
        });

        function<bool(int,int)> relative = [&words](int preI, int curI){
            // only consider one different char
            int n = words[preI].size();
            string &preS = words[preI];
            string &curS = words[curI];
            bool hasDiff = false;
            for(int i = 0, j = i; i < n; i++){
                if(preS[i] == curS[j]){
                    j++;
                    continue;
                }else{
                    if(hasDiff){
                        return false;
                    }else{
                        hasDiff = true;
                        i--;
                        j++;
                    }
                }
            }
            return true;
        };
        function<int(int)> dfs = [&relative, &dfs, &memory, &words](int index){
            int & result = memory[index];
            if (result != -1) return result;
            result = 1;
            int preLength = words[index].size()-1;
            vector<string>::iterator lowerIt = lower_bound(words.begin(), words.begin()+index, preLength,
                [](const string& a, const int size){
                    return a.size() < size;
                });
            vector<string>::iterator upperIt = lower_bound(words.begin(), words.begin()+index, preLength,
                [](const string& a, const int size){
                    return a.size() <= size;
                });
            int preMax = 0;
            for(auto it = lowerIt; it != upperIt; ++it){
                if(relative(it-words.begin(), index))
                    preMax = max(preMax, dfs(it-words.begin()));
            }
            result += preMax;
            return result;
        };
        int result = 0;
        for(int i = n-1; i >= 0; i--){
            result = max(result, dfs(i));
        }
        return result;

    }
};

int main(){
	Solution solution;

	vector<string> price ={"a","b","ab","bac"};
	cout << solution.longestStrChain(price)<< endl;
}