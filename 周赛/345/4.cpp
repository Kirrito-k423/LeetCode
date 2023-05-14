#include <bits/stdc++.h>

using namespace std;



class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        bool adjList[50][50];
        int uniform[50];
        iota(uniform, uniform+50, 0);
        memset(adjList, 0, 50*50*sizeof(bool));
        function<int(int)> father = [&father, &uniform](int x){
            while(uniform[x] != x){
                x = uniform[x];
            }
            return x;
        };
        function<void(int,int)> unionA = [&father, &uniform](int a, int b) {
            int fatherA = father(a);
            int fatherB = father(b);
            int mx = max(fatherA, fatherB);
            int mn = min(fatherA, fatherB);
            uniform[mx] = mn;
        };
        for(auto &edge : edges){
            adjList[edge[0]][edge[1]]=true;
            adjList[edge[1]][edge[0]]=true;
            int mx = max(edge[0], edge[1]);
            int mn = min(edge[0], edge[1]);
            unionA(mx,mn);
        }
        set<int> result;
        map<int, set<int>> unionSet;
        for(int i=0; i<n; i++){
            if(uniform[i]==i){
                result.insert(i);
            }else{
                int root = father(i);
                unionSet[root].insert(i);
            }
        }
        for(auto &value : unionSet){
            const int &root = value.first;
            set<int> &rootSet = value.second;
            rootSet.insert(root);
            vector<int> checkErase(rootSet.begin(), rootSet.end());
            for(int i=0; i<checkErase.size(); i++){
                for(int j=i+1; j<checkErase.size(); j++) {
                    if(adjList[checkErase[i]][checkErase[j]]==false){
                        result.erase(root);
                        break;
                    }
                }
                if(!result.count(root)) break;
            }
        }
        return result.size();
    }
};

int main(){
	Solution solution;
	vector<vector<int>> edges = {{0,1},{0,2},{1,2},{3,4},{3,5}} ;
	cout << solution.countCompleteComponents(6, edges)<< endl;
}