/*
 * @Descripttion: 
 * @version: 
 * @Author: Shaojie Tan
 * @Date: 2022-02-27 23:12:41
 * @LastEditors: Shaojie Tan
 * @LastEditTime: 2022-02-27 23:29:05
 */
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <cfloat>
#include "../tsjCommonFunc.h"
using namespace std;

class Solution {
public:
    struct optimalDivisionData {string format; float value;};
    optimalDivisionData maxValue(vector<int>::iterator First, int n){
        passPrint("maxValue %d",n);  
        optimalDivisionData returnData;
        // int n=nums.size();
        if(n==1){
            returnData.format=to_string(First[0]);
            returnData.value=(float)First[0];
            return returnData;
        }
        if(n==2){
            returnData.format=to_string(First[0])+"/"+to_string(First[1]);
            returnData.value=(float)First[0]/(float)First[1];
            return returnData;
        }
        float result=0;
        int divideI;
        optimalDivisionData tmpBefore;
        optimalDivisionData tmpAfter;
        for(int i=1; i<n; i++){
            optimalDivisionData Before=maxValue(First,i);
            errorPrint("before %s %f",Before.format.c_str(),Before.value);
            optimalDivisionData After=minValue(First+i,n-i);
            
            errorPrint("after %s %f",After.format.c_str(),After.value);
            if(Before.value/After.value>result){
                result = Before.value/After.value;
                tmpBefore=Before;
                tmpAfter=After;
                divideI=i;
            }
        }
        if(divideI==n-1){
            returnData.format=tmpBefore.format+"/"+tmpAfter.format;
            returnData.value=result;
            return returnData;
        }else{
            returnData.format=tmpBefore.format+"/("+tmpAfter.format+")";
            returnData.value=result;
            return returnData;
        }
    }
    optimalDivisionData minValue(vector<int>::iterator First, int n){   
        yellowPrint("minValue %d",n);      
        optimalDivisionData returnData;
        // int n=nums.size();
        if(n==1){
            returnData.format=to_string(First[0]);
            returnData.value=(float)First[0];
            return returnData;
        }
        if(n==2){
            returnData.format=to_string(First[0])+"/"+to_string(First[1]);
            returnData.value=(float)First[0]/(float)First[1];
            return returnData;
        }
        float result=FLT_MAX;
        int divideI;
        optimalDivisionData tmpBefore;
        optimalDivisionData tmpAfter;
        for(int i=1; i<n; i++){
            optimalDivisionData Before=minValue(First,i);
            errorPrint("before %s %f",Before.format.c_str(),Before.value);
            optimalDivisionData After=maxValue(First+i,n-i);
            errorPrint("after %s %f",After.format.c_str(),After.value);
            if(Before.value/After.value<result){
                result = Before.value/After.value;
                tmpBefore=Before;
                tmpAfter=After;
                divideI=i;
            }
        }
        if(divideI==n-1){
            returnData.format=tmpBefore.format+"/"+tmpAfter.format;
            returnData.value=result;
            return returnData;
        }else{
            returnData.format=tmpBefore.format+"/("+tmpAfter.format+")";
            returnData.value=result;
            return returnData;
        }
    }

    string optimalDivision(vector<int>& nums) {
        vector<int>::iterator First = nums.begin();
        int n=nums.size();
        return maxValue(First,n).format;
    }
};

int main(){
	Solution Solution;
    vector<int> input={1000,100,10,2};
	cout << Solution.optimalDivision(input) << endl;
}