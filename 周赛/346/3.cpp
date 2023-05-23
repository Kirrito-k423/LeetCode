#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnswerNum(int num){
        string numStr = to_string(num*num);
        int n = numStr.size();
        int curSum = 0;
        function<bool(int &,int)> dfs = [&n, &num, &dfs, &numStr](int &curSum, int index){
            if(curSum > num) return false;
            if(index == n && curSum==num) 
                return true;
            for(int i = index; i < n; i++){
                int delta = stoi(numStr.substr(index,i-index+1));
                curSum += delta;
                if(dfs(curSum, i+1)){
                    return true;
                }
                curSum -= delta;
            }
            return false;
        };
        for(int i = 1; i <= n; i++){
            int delta = stoi(numStr.substr(0,i));
            curSum += delta;
            if(dfs(curSum, i)){
                return true;
            }
            curSum -= delta;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int result = 0;
        for(int i = 1; i <= n; i++) {
            if(isAnswerNum(i)){
                result += i*i;
            }
        }
        return result;
    }
};

int main(){
	Solution solution;
	// vector<vector<int>> edges = {{0,1},{1,2},{1,3}} ;
	// vector<vector<int>> trips = {{0,3},{2,1},{2,3}};
	// vector<int> price ={2,2,10,6};
	cout << solution.punishmentNumber(9)<< endl;
}