
#include "../tsjCommonFunc.h"
using namespace std;

//  * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //在一层层向下遍历的时候，需要辅助结构存储上一层的节点(有序)，推荐队列
        vector<vector<int>> result;
        queue<TreeNode*> last_floor_nodes, cur_floor_nodes;
        last_floor_nodes.push(root);
        do{
            vector<int> tmp_floor;
            while(!last_floor_nodes.empty()){
                TreeNode * cur_node = last_floor_nodes.front();
                last_floor_nodes.pop();
                cout << cur_node->val <<" ";

                tmp_floor.push_back(cur_node->val);
                if(cur_node->left) cur_floor_nodes.push(cur_node->left);
                if(cur_node->right) cur_floor_nodes.push(cur_node->right);
            }
            last_floor_nodes.swap(cur_floor_nodes);
            cout << endl;
            result.push_back(tmp_floor);
        }while(!last_floor_nodes.empty());
       return result;
    }
};

int main(){
	Solution Solution;
    // string input1();
    // vector<int> input1 = {0,0,0,0};
    TreeNode* right = new TreeNode(20, new TreeNode(15),new TreeNode(7));
    TreeNode* root = new TreeNode(3,new TreeNode(9),right);
	Solution.levelOrder(root);
}