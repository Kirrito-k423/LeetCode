/**
 * Definition for singly-linked list.

 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        priority_queue<pair<int,int>> frontNodes;
		int n = 0;
		vector<int> ans;
		ListNode * cur = head;
		while(cur){
			ans.push_back(0);
			while(frontNodes.top().first < cur->val){
				int popNode = frontNodes.top().second;
				frontNodes.pop();
				ans[popNode]=n;
			}
			frontNodes.push(make_pair(cur->val, n));
			n++;
			cur = cur -> next;
		}
		return ans;
    }
};

int main(){
	Solution S;
	
}