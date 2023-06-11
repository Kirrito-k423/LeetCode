#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;

class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size();
        vector<int> answer;

        vector<pair<int,int>> ordered;
        for(int i = 0; i < n; i++){
            ordered.push_back(make_pair(nums1[i], nums2[i]));
        }
        sort(ordered.begin(), ordered.end());
        for (const vector<int>& query : queries) {
            int xi = query[0];
            int yi = query[1];

            int maxSum = -1; // 最大值初始化为 -1

            // 遍历数组，找到满足条件的最大值
            int index = lower_bound(ordered.begin(), ordered.end(), make_pair(xi,INT_MIN)) - ordered.begin();
            for (int j = index+1; j < n; j++) {
                int &prea = ordered[j-1].first;
                int &a = ordered[j].first;
                if(prea!=a){
                    int &preb = ordered[j-1].second;
                    if (preb >= yi) {
                        int sum = prea + preb;
                        maxSum = max(maxSum, sum);
                    }
                }                
            }
            if(index < n){
                int &a = ordered[n-1].first;
                int &b = ordered[n-1].second;
                if (b >= yi) {
                    int sum = a + b;
                    maxSum = max(maxSum, sum);
                }
            }
            

            answer.push_back(maxSum);
        }

        return answer;
    }
};
