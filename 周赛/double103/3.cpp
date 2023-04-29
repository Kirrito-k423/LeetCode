#include <bits/stdc++.h>

using namespace std;

struct  node
{
    int parentId;
    int value;
    node(int x, int index): value(x), parentId(index){};
};

#define xy(a,b) (a)*n+(b)
node* nodeList[100];
class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        //并查集
        // function<int(int)> parent = [(&nodeList)[100]](int index){
        function<int(int)> parent = [&](int index){
        
            while(index != nodeList[index]->parentId){
                index = nodeList[index]->parentId;
            }
            return index;
        };
        function<int(int,int)> merge = [&](int index1, int index2){
            int mergeI1 = parent(index1);
            int mergeI2 = parent(index2);
            if(mergeI1 != mergeI2){
                int small = min(mergeI1, mergeI2);
                int bigger = max(mergeI1,mergeI2);
                nodeList[bigger]->parentId = small;
                nodeList[small]->value += nodeList[bigger]->value;
                return nodeList[small]->value;
            }else{
                return nodeList[index1]->value;
            }
        };
        int resultMax = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i <m; i++) {
            for (int j = 0; j < n; j++) {
                int fish = grid[i][j];
                resultMax = max(resultMax, fish);
                if(fish){
                    nodeList[xy(i,j)] = new node(fish, xy(i,j));
                    if(i-1>=0 && grid[i-1][j]>0){
                        resultMax = max(resultMax,merge(xy(i,j),xy(i-1,j)));
                    }
                    if((j-1>=0 && grid[i][j-1]>0)){
                        resultMax = max(resultMax,merge(xy(i,j),xy(i,j-1)));
                    }
                }
            }
        }
        return resultMax;
    }
};

int main(){
	Solution solution;
	// vector<vector<int>> edges = {{{0,1},{1,2},{1,3}}} ;
	vector<vector<int>> trips = {{{0,0,9},{1,0,4}}};
	// vector<int> price ={2,2,10,6};
	cout << solution.findMaxFish( trips)<< endl;
}