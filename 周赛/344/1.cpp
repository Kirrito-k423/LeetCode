#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        //前缀的不同数目用set.size()表示
        //后缀的用 count[50]-preCount[50] 不为0的数目
        vector<int> count(50,0); //need -1
        for(auto & x: nums) {
            count[x-1]++;
        }
        vector<int> result;
        set<int> preSet;
        vector<int> preCount(50,0); //need -1
        for(auto & x: nums) {
            preSet.insert(x-1);
            preCount[x-1]++;
            int suffix = 0;
            for(int i=0; i<count.size(); i++) {
                if(count[i]!=0){
                    if(count[i]>preCount[i]){
                        suffix ++;
                    }
                }
            }
            result.push_back(-suffix +preSet.size() );
        }
        return result;
    }
};