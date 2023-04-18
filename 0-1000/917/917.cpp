/*
 * @Descripttion: 
 * @version: 
 * @Author: Shaojie Tan
 * @Date: 2022-02-23 10:04:07
 * @LastEditors: Shaojie Tan
 * @LastEditTime: 2022-02-23 10:14:39
 */
/*
 * @Descripttion: 
 * @version: 
 * @Author: Shaojie Tan
 * @Date: 2022-02-21 11:52:23
 * @LastEditors: Shaojie Tan
 * @LastEditTime: 2022-02-21 12:05:36
 */
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include "../tsjCommonFunc.h"
using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if((65<=s[i] && s[i]<=90) || (97<=s[i] && s[i]<=122)){
                if((65<=s[j] && s[j]<=90) || (97<=s[j] && s[j]<=122)){
                    char tmp=s[i];
                    s[i]=s[j];
                    s[j]=tmp;
                    i++;
                    j--;
                    valuePrint(i);
                    valuePrint(j);
                    std::cout << s << std::endl;
                }else{
                    j--;
                }
            }else{
                i++;
            }
        }
        return s;
    }
};

int main(){
	Solution Solution;
    string input("a-bC-dEf-ghIj");
	cout << Solution.reverseOnlyLetters(input) << endl;
}