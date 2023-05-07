#include <bits/stdc++.h>

using namespace std;

#define ci 0
#define ri 1
#define oi 2
#define ai 3

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        //每次遇到k，应该寻找前面最近的croa来组合
        queue<int> stacks[4];
        // vector<int> result;
        set<int> result;
        for(int i = 0; i < croakOfFrogs.size(); i++){
            char &x = croakOfFrogs[i];
            if(x!='k'){
                //push
                if(x=='c') stacks[ci].push(i);
                if(x=='r') stacks[ri].push(i);
                if(x=='a') stacks[ai].push(i);
                if(x=='o') stacks[oi].push(i);
            }else{// x == 'k'
                if(stacks[0].size()>0 && stacks[1].size()>0\
                && stacks[2].size()>0 && stacks[3].size()>0){
                    int cI = stacks[ci].front();
                    int rI = stacks[ri].front();
                    int oI = stacks[oi].front();
                    int aI = stacks[ai].front();
                    if(cI<rI && rI<oI && oI<aI){
                        stacks[ci].pop();
                        stacks[ri].pop();
                        stacks[oi].pop();
                        stacks[ai].pop();
                        //find the max result[k] < cI
                        // bool found = false;
                        // int maxVal = -1;
                        // int maxValj = -1;
                        // for(int j=0; j<result.size(); j++){
                        //     int &r = result[j];
                        //     if(r<cI){
                        //         // r=i;
                        //         if(r>maxVal){
                        //             maxValj = j;
                        //         }
                        //         found = true;
                        //     }
                        // }
                        // if(found==false){
                        //     result.push_back(i);
                        // }else{
                        //     result[maxValj]=i;
                        // }
                        set<int>::iterator it = lower_bound(result.begin(), result.end(), cI);
                        if(it==result.begin()){
                            result.insert(i);
                        }else{
                            result.erase(--it);
                            result.insert(i);
                        }
                    }else{
                        return -1;
                    }
                }else{
                    return -1;
                }
                
            }
        }
        if(stacks[0].size()==0 && stacks[1].size()==0\
                && stacks[2].size()==0 && stacks[3].size()==0)
            return result.size();
        else
            return -1;
    }
};

int main(){
	Solution solution;
	cout << solution.minNumberOfFrogs("croakcroak")<< endl;
}