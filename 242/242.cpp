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
    bool isAnagram(string s, string t) {
        //由于知道集合大小为 26*2=52
        int count[52];
        memset(count, 0 , sizeof(count));
        for(const auto & x : s){
            cout << x << " " << endl;
            int index = (x > 'Z')?(x-'a'):(x-'A'+26);
            count[index]++;
        }
        for(const auto & x : t){
            int index = (x > 'Z')?(x-'a'):(x-'A'+26);
            count[index]--;
        }
        for(int i=0; i<52; i++){
            if(count!=0){
                return false;
            }
        }
        return true;
    }
};

int main(){
	Solution Solution;
    string input1("anagram");
    string input2("nagaram");
	cout << Solution.isAnagram(input1,input2) << endl;
}