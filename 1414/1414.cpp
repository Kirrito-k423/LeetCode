/*
 * @Descripttion: 
 * @version: 
 * @Author: Shaojie Tan
 * @Date: 2022-02-03 21:38:05
 * @LastEditors: Shaojie Tan
 * @LastEditTime: 2022-02-19 00:19:16
 */
#include <iostream>
#include <vector>
#include "../tsjCommonFunc.h"
using namespace std;
class Solution {
public:
    int globalIndex; 
    std::vector<int> f;
    int findMinFibonacciNumbers(int k) {  
        int firstF=1;
        int sencondF=1;
        f.emplace_back(1);
        while(firstF + sencondF <= k){
            int tmp = firstF + sencondF;
            f.emplace_back(tmp);
            firstF = sencondF;
            sencondF = tmp;
        }
        int ans=0;
        globalIndex = f.size() - 1;
        int index = f.size();
        while(k>0){
			// cout << "k " <<k << endl;
            index = finddata(0,index-1,k);
			// cout << "index " <<index << endl;
            int deletedata = f[index];
            ans++;
            k=k-deletedata;
        }        
        return ans;
    }
    int finddata(int begin, int end, int k){
		// cout << "size " <<f.size() << endl;
		// cout << "end " <<end << endl;
        int tmp=f[end];
		// cout << "tmp " <<tmp << endl;
        if(tmp<=k){
            return end;
        }else{
            int tmpIndex=(begin+end)/2;
            tmp=f[tmpIndex];
            if(tmp==k)
                return tmpIndex;
            else if(tmp>k){
                return finddata(begin,tmpIndex-1,k);
            }else{
                return finddata(tmpIndex+1,end-1,k);
            }
        }
    }

};

int main(){
	Solution Solution;
    errorPrint("yahaha");
	// cout << 2 << endl;
	cout << Solution.findMinFibonacciNumbers(7) << endl;
}