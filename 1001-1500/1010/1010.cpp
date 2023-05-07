#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        //变量到第i个，记录前面出现的候补的个数
        vector<int> prePartialSumCount(60,0); // 0~59'
        int result = 0;
        for(int & x : time) {
            result += prePartialSumCount[x%60];
            prePartialSumCount[(60-(x%60))%60]++;
        }
        return result;
    }
};