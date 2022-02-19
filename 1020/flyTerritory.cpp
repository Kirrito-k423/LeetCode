#include <iostream>
#include <vector>
#include <unordered_map>
#include "../tsjCommonFunc.h"
using namespace std;
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        #define pos2num(i,j) (i)*n+j
        int m=grid.size();
        int n=grid[0].size();
        unordered_map<int, int> neighbor;//(location,num)
        unordered_map<int, int> parent;//if parent[n]=n means it’s end parent
        unordered_map<int, int> resultAloneSet; // 1 means not belongs to edge
        vector<int> beforeLine(n,-1),currentLine(n,-1);//-1 means no parent
        for(int i=0; i<m; i++){
            int andi=1;
            if(i==0 || i==m-1){
                andi=0;
            }
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    currentLine[j]=-1;
                    continue;
                }   
                //grid[i][j]==1
                int location=pos2num(i,j);
                int before=beforeLine[j];
                if(j==0){
                    if(before==-1){
                        neighbor[location]=1;
                        parent[location]=location;
                        currentLine[j]=location;
                        resultAloneSet[location]=0;
                    }else{
                        while (parent[before]!=before){
                            //parent
                            before=parent[before];
                        }
                        neighbor[before]++;
                        // parent[location]=before;
                        currentLine[j]=before;
                        resultAloneSet[before]=0;
                    }
                }else{
                    int previous=currentLine[j-1];
                    if(before==-1 && previous==-1){
                        neighbor[location]=1;
                        parent[location]=location;
                        currentLine[j]=location;
                        if(j!=n-1){
                            resultAloneSet[location]=1&&andi;
                        }else{
                            resultAloneSet[location]=0;
                        }
                    }else if(before==-1){//previous!=-1
                        //check parent
                        while (parent[previous]!=previous){
                            //parent
                            previous=parent[previous];
                        }
                        neighbor[previous]++;
                        // parent[location]=previous;
                        currentLine[j]=previous;
                        if(j==n-1){
                            resultAloneSet[previous]=0;
                        }else{
                            resultAloneSet[previous]&=andi;
                        }
                    }else if(previous==-1){//before!=-1
                        //check parent
                        while (parent[before]!=before){
                            //parent
                            before=parent[before];
                        }
                        neighbor[before]++;
                        // parent[location]=before;
                        currentLine[j]=before;
                        if(j==n-1){
                            resultAloneSet[before]=0;
                        }else{
                            resultAloneSet[before]&=andi;
                        }
                    }else{//all add to before
                        while (parent[before]!=before){
                            //parent
                            before=parent[before];
                        }
                        while (parent[previous]!=previous){
                            //parent
                            previous=parent[previous];
                        }
                        if(before!=previous){
                            neighbor[before]+=(neighbor[previous]+1);
                            neighbor.erase(previous);
                            parent[previous]=before;
                            // parent[location]=before;
                            currentLine[j]=before;
                            if(j==n-1){
                                resultAloneSet[before]=0;
                            }else{
                                resultAloneSet[before]&=(resultAloneSet[previous]&andi);
                            }
                            resultAloneSet.erase(previous);
                        }else{
                            neighbor[before]+=1;
                            currentLine[j]=before;
                            if(j==n-1){
                                resultAloneSet[before]=0;
                            }else{
                                resultAloneSet[before]&=(resultAloneSet[previous]&andi);
                            }
                        }
                        
                    }
                }
            }
            
            splitPrint("i %d",i);
            valuePrint(andi);
            vectorPrint(beforeLine);
            beforeLine=currentLine;
            
            vectorPrint(currentLine);
            mapPrint(neighbor);
            mapPrint(parent);
            mapPrint(resultAloneSet);
        }
        int ans=0;
        for (unordered_map<int, int>::iterator it=resultAloneSet.begin(); it!=resultAloneSet.end(); ++it){
            if(it->second==1){
                int loc=it->first;
                while(parent[loc]!=loc){
                    loc=parent[loc];
                }
                ans+=neighbor[loc];
            }
        }
        return ans;
    }
};

int main(){
	Solution Solution;
    // testTSJ();
	// cout << 2 << endl;
    vector<vector<int>> grid {{0,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0}};
	vector2Print(grid);
    // printf("%d",grid[0][1]);
    cout << Solution.numEnclaves(grid) << endl;
}