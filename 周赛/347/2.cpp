#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(\
            vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> result(m, vector<int>(n,0));
        // int bottomRight[min(m,n)];
        // set<int> bottomRightSet;
        // for(int i = m-1, j = n-1; i>=0&&j>=0; i--,j--){
        //     bottomRightSet.insert(grid[i][j]);
        //     bottomRight[m-1-i] = bottomRightSet.size();
        // }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int bottomRightValue = 0;
                // int distanceBottomRight = min(m-1-i,n-1-j);
                // if(distanceBottomRight<=0){
                //     bottomRightValue = 0;
                // }else{
                //     bottomRightValue = bottomRight[distanceBottomRight-1];
                // }
                set<int> bottomRightSet;
                for(int p = i+1, q = j+1; p<m&&q<n; p++,q++){
                    bottomRightSet.insert(grid[p][q]);          
                }
                bottomRightValue = bottomRightSet.size();
                int topRightValue = 0;
                set<int> topLeftSet;
                for(int p = i-1, q = j-1; p>=0&&q>=0; p--,q--){
                    topLeftSet.insert(grid[p][q]);          
                }
                topRightValue = topLeftSet.size();
                result[i][j] = abs(topRightValue-bottomRightValue);
            }
        }
        return result;
    }
};

// [
// [15     42      48      22     36   47    13    23       31     41]     
// [25     3       44      17    37     9      14    37     4      43]       
// [7      15      38     10       25    7     37   6     43        4]  
// [50     9       14      36    35     36     44        17  10   44]      
// [46     50      45      28     10   18    18    3    42     24]    
// [14     11      13      32     37   31    50    32       12     38]     
// [44     24      42      9       32   40       8   20    46    39]      
// [33     5       42      30      20     37     26     38  30   30]      
// [32     39      31      33     41       23    4     29      44    22]   
// [8      8       11     21      9       2      37      19     30   37]]