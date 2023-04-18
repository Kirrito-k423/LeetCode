
#include "../tsjCommonFunc.h"
using namespace std;
class Solution {
public:
    const pair<int,int> input[6]={make_pair(2,4),make_pair(1,3),make_pair(3,4)\
        ,make_pair(2,3),make_pair(1,4),make_pair(1,2)};
    bool test(vector<vector<int>>& grid, int n, int m, int before){
        while(m<grid[0].size()&&n<grid.size()){    
            if(m==0&&n==0) return false; //loop
            int pattern = grid[n][m]-1;
            if(before==input[pattern].first){
                if(m==grid[0].size()-1 && n==grid.size()-1)
                    break;
                before=input[pattern].second;
            }else if (before==input[pattern].second){
                if(m==grid[0].size()-1 && n==grid.size()-1)
                    break;
                before=input[pattern].first;
            }else{
                return false;
            }
            if(before==1){
                before=3;
                n--;
            }
            else if(before==2){
                before=4;
                m++;
            } 
            else if(before==3){
                before=1;
                n++;
            } 
            else{
                before=2;
                m--;
            }
        }
        if(m==grid[0].size()-1 && n==grid.size()-1) return true;
        else return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        //除开起点可能从两处出发，其余中间道路，只有一进一出，需要匹配
        //顺时针 是 1，2，3，4
        int m=0, n=0;
        int before = 0;
        if(grid[0].size()==1&&grid.size()==1) return true;
        if(grid[m][n]==5){
            return false;
        }
        if(grid[m][n]==1||grid[m][n]==6){
            if(grid[0].size()!=1)
                return test(grid,0,1,4);
            else
                return false;
        }else if(grid[m][n]==2||grid[m][n]==3){
            if(grid.size()!=1)
                return test(grid,1,0,1);
            else
                return false;
        }
        if(grid[m][n]==4){
            return ((grid.size()!=1)?test(grid,1,0,1):false) || \
                    ((grid[0].size()!=1)?test(grid,0,1,4):false);
        }
        return true;
    }
};

int main(){
	Solution Solution;
    // string input1();
    vector<vector<int>> input1 = {{4,3,3},{6,5,2}};
    // {{6,3},{4,5},{6,3}};
    // {{4,1},{6,1}};
    // {{1,2,1},{1,2,1}};
	cout << Solution.hasValidPath(input1) <<endl;
}