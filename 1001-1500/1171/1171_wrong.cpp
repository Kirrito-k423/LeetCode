
#include <bits/stdc++.h>

using namespace std;


//  * Definition for singly-linked list.
//  struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        //转换成数组存储前缀和
        //辅助数据结构 map<int, set<int>> 记录出现位置/次数，从后往前
        //合并，采取跳转删除策略，需要提前存储第i node的位置
        vector<ListNode *> arrayNode;
        ListNode* cur = head;
        while(cur!=nullptr){
            arrayNode.push_back(cur);
            cur = cur->next;
        }
        map<int,set<int>> preSumLocation;
        vector<int> preSum;
        preSum.push_back(arrayNode[0]->val);
        preSumLocation[arrayNode[0]->val]=set<int>({0});
        int n = arrayNode.size();
        for(int i=1; i<n; i++){
            int tmp = arrayNode[i]->val + *(preSum.end()-1);
            preSum.push_back(tmp);
            if(preSumLocation.count(tmp)){
                preSumLocation[tmp].insert(i);
            }else{
                preSumLocation[tmp]=set<int>({i});
            }
        }
        for(int i=0; i<n;){
            int toPair = preSum[i];
            if(preSumLocation[toPair].size()>1){
                auto it = preSumLocation[toPair].rbegin();
                if(*it!=i){
                    arrayNode[i]->next=arrayNode[*it]->next;
                    i = *it;
                    continue;
                }     
            }
            i++;//or
        }
        return head;
    }
};