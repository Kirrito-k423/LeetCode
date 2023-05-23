#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, \
        int numWanted, int useLimit) {
            vector<pair<int ,int>> sortedValues;
            map<int,int> labelCount;
            for(int i = 0; i < values.size(); i++) {
                sortedValues.push_back({values[i], labels[i]});
            }
            sort(sortedValues.begin(), sortedValues.end(), [](const pair<int ,int>& a, const pair<int ,int> &b){
                return a.first > b.first;
            });
            int result = 0;
            int numLimit = 0;
            for(int i = 0; i < sortedValues.size(); i++){
                int &curLabel = sortedValues[i].second;
                if(labelCount[curLabel] < useLimit){
                    result += sortedValues[i].first;
                    numLimit++;
                    if(numLimit==numWanted){
                        break;
                    }
                    labelCount[curLabel]++;
                }
            }
            return result;
    }
};