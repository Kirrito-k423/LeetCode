#include <queue>
#include <map>
#include <vector>
#include <cstring>
#include <unordered_set>
using namespace std;
class Graph {
public:
    int Size = 0;
    int AdjacencyList[100][100];
    
    Graph(int n, vector<vector<int>>& edges) {
        memset(AdjacencyList, 0, 100*100*sizeof(int));
        Size = n;
        for(auto &edge : edges){
            AdjacencyList[edge[0]][edge[1]] = edge[2];
        }
    }
    
    void addEdge(vector<int> edge) {
        AdjacencyList[edge[0]][edge[1]] = edge[2];
    }
    
    void subPath(int &cur, int i, int &result, int &node2, int (&passNode)[100]){
        if(i==node2){
            result = min(result,cur);
            return;
        }
        for (int j = 0; j < Size; j++) {
            if(passNode[j]==0 && AdjacencyList[i][j]){
                //不是双向没有环，不要记录父亲
                passNode[j]++;
                cur += AdjacencyList[i][j];
                subPath(cur, j, result, node2, passNode);
                passNode[j]--;
                cur -= AdjacencyList[i][j];
            }
        }
    }
    int shortestPath(int node1, int node2) {
        int passNode[100] = {0};
        memset(passNode, 0, sizeof(passNode));
        if(node1 == node2) return 0;
        int result = INT_MAX;
        int  cur = 0;
        passNode[node1]++;
        for (int i = 0; i < Size; i++) {
            if(AdjacencyList[node1][i]){
                passNode[i]++;
                //不是双向没有环，不要记录父亲
                cur += AdjacencyList[node1][i];
                subPath(cur, i, result, node2, passNode);
                passNode[i]--;
                cur -= AdjacencyList[node1][i];
            }
        }
        if(result==INT_MAX)
            return -1;
        else
            return result;
    }
};

// 超时，需要带记忆的Dijkstra最短路径算法