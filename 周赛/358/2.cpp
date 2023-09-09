#include <bits/stdc++.h> 
// stdc++.h 几乎包含所有常用头文件
using namespace std;
typedef pair<int,int>PII;
const int MOD = 1e9 + 7;
const int INF = 2e9;
// #define x first
// #define y second
typedef long long ll;
const int N=1E5+10,M=210;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        // carry bit if digist bigger than 4
		// if should new 1
		ListNode * ans = new ListNode(0, head);
		ListNode * cur = ans;
		while(cur->next != nullptr){
			ListNode * addend = cur->next;
			if(addend->val > 4){
				cur->val += 1;
			}
			addend->val = (addend->val*2)%10;
			cur = addend;
		}
		if(ans->val==0){
			delete ans;
			return head;
		}else{
			return ans;
		}
    }
};

// int main(){
// 	Solution solution;
// 	vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
// 	vector<int> price ={2,2,10,6};
// 	vector<vector<int>> trips = {{{0,3},{2,1},{2,3}}};
// 	cout << solution.minimumTotalPrice(4, edges, price, trips)<< endl;
// }