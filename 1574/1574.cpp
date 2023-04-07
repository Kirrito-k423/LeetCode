#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        //寻找答案的补集，三种情况：首尾的非递减子数组，和由首尾拼接而成的非递减数组
        
        int N = arr.size();
        if(N==1) return 0;
        int front = arr[0];
        int back_end = arr[N-1];
        int front3 = arr[0];
        int back_end3 = arr[N-1];
        int result_front =1, result_end=1;
        int result_merge = 0;
        bool flag1 =false, flag2 =false, flag3 = false; //true represent finished
        if(front3 <= back_end3){
            result_merge += 2;
        }else{
            flag3 =true;
        }
        for(int i=1; i<N; i++){
            if(!flag1)
                if(arr[i]>=front){
                    result_front += 1;
                    front = arr[i];
                }else{
                    flag1=true;
                }
            if(!flag2)
                if(arr[N-1-i]<=back_end){
                    result_end += 1;
                    back_end = arr[N-1-i];
                }else{
                    flag2=true;
                }
            if(i>=N-1-i){
                if(!flag3 && i==N-1-i && front3<= arr[N-1-i] && back_end3>= arr[N-1-i])
                    result_merge += 1;
                flag3=true;
            }
            if(!flag3)
                if(!flag1 && !flag2){
                    if(front<=back_end){
                        front3 = front;
                        back_end3 =back_end;
                        result_merge += 2;
                    
                    }else if(min(front3,arr[i-1])<=back_end){
                        front3 = arr[i-1];
                        back_end3 =back_end;
                        result_merge += 1; //todo: 交错
                        // flag3=true;
                    }else if(front<=max(arr[N-i],back_end3)){
                        front3 = front;
                        back_end3 =arr[N-i];
                        result_merge += 1; //todo: 交错
                        // flag3=true;
                    }else{
                        flag3=true;
                    }
                }else if(flag1 && !flag2){
                    if(min(front3,front)<=back_end)
                        result_merge += 1;
                    else{
                        flag3=true;
                    }
                
                }else if(!flag1 && flag2){
                    if(front<=back_end)
                        result_merge += 1;
                    else{
                        flag3=true;
                    }
                }else{
                    flag3=true;
                }
            if(flag1 && flag2 && flag3) break;
        }
        return N-max(result_merge,max(result_front,result_end));
        }

};


int main(int argc, const char * argv[]) {
    Solution s;
    vector<int> v = {11,26,3,14,24,6,10,16,32,9,36,24,27,17,31,32,35,36,11,22,30};
    // int input;
    // while(cin >> input){
    //     cout << input << endl;
    //     v.push_back(input);
    // }
    cout << s.findLengthOfShortestSubarray(v) << endl;
    return 0;
}