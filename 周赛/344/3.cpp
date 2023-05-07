#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        //模拟， 每次改色对前后，新增或者破坏相邻同色
        int colorArray[n];
        memset(colorArray, 0, sizeof(colorArray));
        int changeN = queries.size();
        vector<int> result(changeN, 0);
        int curSamePair = 0;
        for (int i = 0; i < changeN; ++i) {
            int &changeIndex = queries[i][0];
            int &toColor = queries[i][1];
            if(changeIndex!=0 && colorArray[changeIndex-1]!=0 ){
                if(colorArray[changeIndex]==colorArray[changeIndex-1]){
                    //已有
                    if(colorArray[changeIndex]!=toColor){
                        curSamePair--;
                    }
                }else if(colorArray[changeIndex-1]==toColor){
                    curSamePair++;
                }
            }
            if(changeIndex!=n-1 && colorArray[changeIndex+1]!=0 ){
                if(colorArray[changeIndex]==colorArray[changeIndex+1]){
                    //已有
                    if(colorArray[changeIndex]!=toColor){
                        curSamePair--;
                    }
                }else if(colorArray[changeIndex+1]==toColor){
                    curSamePair++;
                }
            }
            colorArray[changeIndex]=toColor;
            result[i]=curSamePair;
        }
        return result;
    }
};


int main(){
	Solution solution;
	vector<vector<int>> trips = {{0,2},{1,2},{3,1},{1,1},{2,1}};
	solution.colorTheArray(4, trips);
}