#include<bits/stdc++.h>

using namespace std;

// struct TreeNode {
// 	int val;
// 	TreeNode *left;
// 	TreeNode *right;
// 	TreeNode() : val(0), left(nullptr), right(nullptr) {}
// 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// 	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

typedef long long ll;
class TrieWithPos{
private:
	int pos = 0;
	int depth;
	TrieWithPos *left = nullptr;
	TrieWithPos *right = nullptr;
public:
	TrieWithPos(TreeNode *root, ll pos_input, int depth, vector<pair<ll,ll>> & max_min):pos(pos_input), depth(depth){
		//change max min
		if(max_min.size() < depth){
			max_min.emplace_back(pair<ll,ll>{pos_input,pos_input});
		}else{
			max_min[depth-1].first = min(max_min[depth-1].first, pos_input);
			max_min[depth-1].second = max(max_min[depth-1].second, pos_input);
		}
		
		if(root->left){
			this->left = new TrieWithPos(root->left, 2* pos_input - 2*max_min[depth-1].first, depth+1, max_min);
		}
		if(root->right){
			this->right = new TrieWithPos(root->right, 2* pos_input+1 - 2*max_min[depth-1].first, depth+1, max_min);
		}
	}
	~TrieWithPos(){
		delete this->left;
		delete this->right;
	}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
		vector<pair<ll,ll>> max_min(0); // max - min
		TrieWithPos * root_tree = new TrieWithPos(root, 0, 1, max_min);
		ll result=0;
		for(auto &pair_max_min: max_min){
			result = max(result, pair_max_min.second - pair_max_min.first);
		}
		return result+1;
    }
};