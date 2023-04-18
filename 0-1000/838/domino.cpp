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
    string pushDominoes(string dominoes) {
        #define origin -1
        #define rightNum 0
        #define leftNum 1
        #define beginState 2
        #define changeState 3
        #define tmpendState 4
        #define endState 5
        // #define nopushState 1
        //寻找"."的状态
        function<void(int, int, int, int)> changeStateFunc = [&](int leftState,int rightState,int leftOrderNum,int rightOrderNum) {
            yellowPrint("%d %d %d %d", leftState, rightState, leftOrderNum, rightOrderNum);
            if(leftState==rightNum && (rightState==rightNum || rightState==endState)){
                for(int i=leftOrderNum; i<=rightOrderNum; i++){
                    dominoes[i]='R';
                }
            }else if(rightState==leftNum && (leftState==leftNum || leftState==beginState)){
                for(int i=leftOrderNum; i<=rightOrderNum; i++){
                    dominoes[i]='L';
                }
            }else if(leftState==rightNum && rightState==leftNum){
                passPrint("%d %d %d %d", leftState, rightState, leftOrderNum, rightOrderNum);
                for(int i=leftOrderNum; i<( (float)rightOrderNum+ (float)leftOrderNum)/2; i++){
                    dominoes[i]='R';
                    dominoes[rightOrderNum-(i-leftOrderNum)]='L';
                }
            }
        };
        int leftState=origin,rightState=origin;
        int leftOrderNum=origin,rightOrderNum=origin;
        int state=beginState;
        for(int i=0; i<dominoes.size(); i++){
            if(state==beginState){
                if(dominoes[i]=='R'){
                    leftState=rightNum;
                    state=tmpendState;
                }else if(dominoes[i]=='L'){
                    leftState=leftNum;
                    state=tmpendState;
                }else if(dominoes[i]=='.'){
                    leftState=beginState;
                    leftOrderNum=0;
                    state=changeState;
                }
            }else if(state==changeState){
                if(dominoes[i]=='.'){
                    if(i==dominoes.size()-1){
                        rightState=endState;
                        rightOrderNum=i;
                    }else{
                        continue;
                    }
                }else if (dominoes[i]=='R'){
                    rightState=rightNum;
                    rightOrderNum=i-1;
                }else if (dominoes[i]=='L'){
                    rightState=leftNum;
                    rightOrderNum=i-1;
                }
                changeStateFunc(leftState,rightState,leftOrderNum,rightOrderNum);
                leftState=rightState;
                //clear??
                state=tmpendState;
            }else if(state==tmpendState){
                if(dominoes[i]=='R'){
                    leftState=rightNum;
                }else if(dominoes[i]=='L'){
                    leftState=leftNum;
                }else if(dominoes[i]=='.'){
                    if(i==dominoes.size()-1){
                        leftOrderNum=i;
                        rightState=endState;
                        rightOrderNum=i;
                        changeStateFunc(leftState,rightState,leftOrderNum,rightOrderNum);
                    }else{
                        leftOrderNum=i;
                        state=changeState;
                    }
                    
                }
            }
        }
        return dominoes;
    }
};

int main(){
	Solution Solution;
    string input(".L.R.");
	cout << Solution.pushDominoes(input) << endl;
}