#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        //贪心：免费的解决高cost的
        //发现：免费的是最快的，付费优先平均cost时长长的(也不超过n)，优先cost小的
        //两者随便选择，覆盖后。取最小即可。
        int result = INT_MAX;
        int n = cost.size();
        vector<int> avgTime(n);
        vector<int> costFirst(n);
        iota(avgTime.begin(), avgTime.end(), 0);
        iota(costFirst.begin(), costFirst.end(), 0);
        sort(avgTime.begin(),avgTime.end(), [&cost,&time](const int a, const int b)
        {return (float)time[a]/cost[a] > (float)time[b]/cost[b];});
        sort(costFirst.begin(),costFirst.end(), [&cost,&time](const int a, const int b)
        {return cost[a] < cost[b];});

        set<int> chosed;
        int tmpCost=0;
        int tmpTime=0;

        function<int(int,int)> dfs = [&](int i1, int i2){
            if(tmpTime>=n-chosed.size()){
                result = min(result,tmpCost);
                return 0;
            }
            // if(i1>=n || i2>=n) return 0;
            int tmpI = avgTime[i1];
            if(chosed.count(tmpI)){
                dfs(i1+1,i2);
            }else{
                tmpCost += cost[tmpI];
                tmpTime += time[tmpI];
                chosed.insert(tmpI);
                dfs(i1+1,i2);
                chosed.erase(tmpI);
                tmpCost -= cost[tmpI];
                tmpTime -= time[tmpI];
            }
            // dfs(i1+1,i2);
            
            tmpI = avgTime[i2];
            if(chosed.count(tmpI)){
                dfs(i1,i2+1);
            }else{
                tmpCost += cost[tmpI];
                tmpTime += time[tmpI];
                chosed.insert(tmpI);
                dfs(i1,i2+1);
                chosed.erase(tmpI);
                tmpCost -= cost[tmpI];
                tmpTime -= time[tmpI];
            }
            // dfs(i1,i2+1);
            return 0;
        };
        dfs(0,0);

        return result;
    }
};


// int main(){
// 	Solution solution;
// 	// vector<vector<int>> edges = {{0,1},{1,2},{1,3}} ;
// 	// vector<vector<int>> trips = {{0,3},{2,1},{2,3}};
// 	vector<int> cost  ={2,3,4,2};
// 	vector<int> time   ={1,1,1,1};
// 	cout << solution.paintWalls(cost, time)<< endl;
// }

// 输入：
// [42,8,28,35,21,13,21,35]
// [2,1,1,1,2,1,1,2]
// 输出：
// 77
// 预期：
// 63