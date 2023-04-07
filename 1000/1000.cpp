#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    void Backtracking(int i, int &ans, int &cur){
        //什么数据结构来保存该值
    }
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if (n % (k-1) != 1) return -1;
        //动态规划，转移方程难写。每次贪心最小的？暴力方法？
        int ans = INT_MAX;
        int cur = 0;
        int moveCount = n / (k-1);
        while (moveCount--) {

        }
    }
};