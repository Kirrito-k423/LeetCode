/*
 * @Descripttion: 
 * @version: 
 * @Author: Shaojie Tan
 * @Date: 2022-02-27 23:12:41
 * @LastEditors: Shaojie Tan
 * @LastEditTime: 2022-03-01 16:43:54
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
    string convert(string s, int numRows) {
        //[0~2*numRows-3] total 2*numRows-2 number
        //for the top and bottom i
        //s[i] will connect behind with s[i+numRows-2+numRows] 
        //for i in the medium 
		if(numRows==1)
			return s;
        vector<string> ans(numRows,"");
        int len=s.length();
        for(int i=0; i<numRows; i++){
            if(i==0 || i==numRows-1){
                for(int j=i; j<len; j+=2*numRows-2){
                    ans[i]+=s[j];
                    
                }
				// yellowPrint("%s", ans[i]);
				// cout << ans[i] << endl;
            }else{
                for(int j=i; j<len; j+=2*numRows-2){
                    ans[i]+=s[j];
					ans[i]+=s[j+2*numRows-2-2*i];
                }
				// passPrint("%s", ans[i]);
				// cout << ans[i] << endl;
            }
        }
        string result("");
        for(auto &i:ans){
            result+=i;
        }
        return result;
    }
};

int main(){
	Solution Solution;
    string input("A");
	int input2=1;
	cout << Solution.convert(input,input2) << endl;
}