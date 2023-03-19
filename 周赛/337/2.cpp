#include <vector>
#include <iostream>
using namespace std;

struct Position
{
    int x, y;
    Position(int x,int y) :x(x), y(y){}
};

#define try(m,n,p) if((p) && grid[n][m]==step+1){ node.x=m; node.y=n; return true;}  
class Solution {
public:
    bool findNextNode(vector<vector<int>>& grid, Position &node, int step){
        int n = grid.size();
        int x = node.x, y=node.y;
        try(x-2, y-1, x-2 >=0 && y-1 >=0)
        try(x-1, y-2, x-1 >=0 && y-2 >=0)
        try(x+2, y-1, x+2 <n && y-1 >=0)
        try(x+1, y-2, x+1 <n && y-2 >=0)
        try(x+2, y+1, x+2 <n && y+1 <n)
        try(x+1, y+2, x+1 <n && y+2 <n)
        try(x-2, y+1, x-2 >=0 && y+1 <n)
        try(x-1, y+2, x-1 >=0 && y+2 <n)
        return false;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        //模拟每一步，8种情况里，必须有 step+1
        int n = grid.size();
        int step=0;
        Position node(0,0);
        for(; step<n*n-1; step++){
            if(!findNextNode(grid, node, step)){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution A;
    vector<vector<int>> grid = {{0,3,6},{5,8,1},{2,7,4}};
    cout << A.checkValidGrid(grid) << endl;
}