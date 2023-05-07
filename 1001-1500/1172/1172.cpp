#include <bits/stdc++.h>

using namespace std;

class DinnerPlates {
public:
    int stackSize;
    vector<stack<int>> DPStackList;
    DinnerPlates(int capacity) {
        int stackSize = capacity;
    }
    
    void push(int val) {
        for(int i = 0; i < DPStackList.size(); i++){
            if(DPStackList[i].size() < stackSize){
                DPStackList[i].push(val);
                return;
            }
        }
        stack<int> tmp;
        tmp.push(val);
        DPStackList.push_back(tmp);
    }
    
    int pop() {
        for(int i = DPStackList.size()-1; i>=0; i--){
            if(DPStackList[i].size()>0){
                int result = DPStackList[i].top();
                DPStackList[i].pop();
                return result;
            }
        }
        return -1;
    }
    
    int popAtStack(int index) {
        if(DPStackList.size() <= index){
            return -1;
        }
        stack<int> &Stack = DPStackList[index];
        if(Stack.size()>0){
            int result = Stack.top();
            Stack.pop();
            return result;
        }else{
            return -1;
        }
    }
};


int main(){
	DinnerPlates D = DinnerPlates(2); 
    D.push(1);
    D.push(2);
    D.push(3);
    D.push(4);
    D.push(5); 
    D.popAtStack(0);
    D.push(20); 
    D.push(21); 
}
/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */