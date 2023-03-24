// 题目描述：
// 现在有若干节点。每个节点上有能量塔。所有节点构成一棵树。
// 某个节点u可以为和u距离不超过给定值的节点各提供一点能量
// 此处距离的定义为两个节点之间经过的边的数量。特别的，节点u到本身的距离为0。
// 现在给出每个节点上的能量塔可以为多远的距离内的点提供能量。
// 小美想要探究每个节点上的能量值具体是多少。你的任务是帮助小美计算得到，并依次输出.
// 输入描述：
// 第一行一个整数N,表示节点的数量
// 接下来一行N个以空格分开的整数，依次表示节点1，节点2，……，
// 节点N的能量塔所能提供能量的最远距离。
// 接下来N-1行，
// 每行两个整数，表示两个点之间有一条边。
// 1N≤500，节点上能量塔所能到达的最远距离距离不会大于500.
// 输出描述：
// 一行N个整数
// 依次表示节点1，节点2，，节点N上的能量值

// 首先将输入构造成邻接表，然后遍历树的每个节点，但是每次遍历都没有利用重复数据与计算，不如
    // 根据邻接表构造邻接距离矩阵)

// int neighbor[N][N];
// vector<vector<int>> neighbor(N);

#include<iostream>
#include<cstring>
using namespace std;

const int kMax = 500;

int dist[kMax][kMax];
int graph[kMax][kMax];

int n;
int energy_dist[kMax];
int ans[kMax];

int main(){
  cin >> n;
  int u, v;
  for (int i = 0; i < n; i++) {
    cin >> energy_dist[i];
  }
  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < n; j++) {
      dist[i][j] = 10000;
    }
    dist[i][i] = 0;
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> v;
    u--;
    v--;
    graph[u][v] = graph[v][u] = 1;
    dist[u][v] = dist[v][u] = 1;
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int val = dist[i][k] + dist[k][j];
        if (dist[i][j] > val)
          dist[i][j] = val;
      }
    }
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (energy_dist[i] >= dist[i][j])
        ans[j] ++;
    }

  }
  
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
