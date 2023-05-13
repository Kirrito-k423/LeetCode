#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> binaryOne(int x){
        vector<int> result;
        int index = 0;
        while(x != 0){
            if(x%1==1) result.push_back(index);
            x >>= 1;
            index++;
        }
        return result;
    } 
    int highestOne(int x){
        int index = 0;
        while(x != 0){
            x >>= 1;
            index++;
        }
        return index;
    }
    long long result2longlong(int (&in)[64]){
        long long result;
        for(int i = 0; i <64 ; i++){
            if(in[i] != 0){
                result |= 1<<i;
            }
        }
        return result;
    }
    long long maximumOr(vector<int>& nums, int k) {
        //先不考虑long long 溢出
        int result[64];
        int highestIndex = 0;
        vector<vector<int>> highestList(0, vector<int>(0));
        vector<vector<int>> highestPos2Num(64, vector<int>(0));
        memset(result, 0, sizeof(result));
        for(auto & num : nums){
            auto indexList = binaryOne(num);
            if(*indexList.rbegin()>highestIndex){
                highestList.clear();
                highestPos2Num.clear();
                int i = highestList.size();
                for(auto & pos : indexList){
                    highestPos2Num[pos].push_back(i);
                }
                highestList.push_back(indexList);
            }else if(*indexList.rbegin()==highestIndex){
                int i = highestList.size();
                for(auto & pos : indexList){
                    highestPos2Num[pos].push_back(i);
                }
                highestList.push_back(indexList);
            }
            for(auto &index :indexList){
                result[index]++;
            }
        }
        //move the biggest fittest One
        if(highestList.size()==1){
            for(auto &index : highestList[0]){
                result[index]--;
                result[index+k]++;
            }
            return result2longlong(result);
        }
        int fittestOneIndex = 0;
        if(k==1){
            //find first unfull position
            for(int i = highestIndex; i >= 0; i--){
                if(result[i]==0 && highestPos2Num[i].size()>0){
                    //simple
                    fittestOneIndex = highestPos2Num[i][0];
                    break;
                }
            }
            for(auto &index : highestList[fittestOneIndex]){
                result[index]--;
                result[index+k]++;
            }
            return result2longlong(result);
        }
        return result2longlong(result);
    }   
};