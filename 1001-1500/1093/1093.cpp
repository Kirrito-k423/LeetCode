#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        bool isGetMin = false;
        int resultMin = INT_MAX;
        int resultMax = INT_MIN;
        int resultMode = 0;
        int modeCount = 0;
        long long sum = 0;
        long long totalCount = accumulate(count.begin(), count.end(),0);
        int getMedianCount = 0;
        long long medianIndex1 = (totalCount-1) / 2 + 1;
        long long medianIndex2 = (totalCount) / 2 + 1;
        double medianSum = 0;
        int curCount = 0;
        for(int i = 0; i < count.size(); i++) {
            if(count[i]==0) continue;
            if(!isGetMin){
                resultMin = i;
                isGetMin = true;
            }
            resultMax   = i;
            if(count[i]>modeCount){
                modeCount = count[i];
                resultMode = i;
            }
            sum += (long long)count[i]*i;
            if(getMedianCount>=2) continue;
            if(curCount <medianIndex1 && medianIndex1 <= curCount + count[i]){
                getMedianCount++;
                medianSum += i;
            }
            if(curCount <medianIndex2 && medianIndex2 <= curCount + count[i]){
                getMedianCount++;
                medianSum += i;
            }
            curCount+=count[i];
        }
        return {(double)resultMin, (double)resultMax, ((double)sum)/totalCount ,\
                medianSum/2, (double)resultMode};
    }
};