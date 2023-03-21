// 题目描述：
// 现在商店里有N个物品，每个物品有原价和折扣价。
// 小美想要购买商品。小美拥有X元，一共Y张折扣券。
// 小美需要最大化购买商品的数量，并在所购商品数量尽量多的前提下，尽量减少花费
// 你的任务是帮助小美求出最优情况下的商品购买数量和花费的钱数。
// 输入描述：
// 第一行三个整数，以空格分开，分别表示N,X,Y。
// 接下来N行，每行两个整数，以空格分开，表示一个的原价和折扣价
// 1≤N≤100,1≤X≤5000,1≤Y≤50，每个商品原价和折扣价均介于[1,50]之间.
// 输出描述：
// 一行，两个整数，以空格分开。
// 第一个数字表示最多买几个商品，第二个数字表示在满足商品尽量多的前提下所花费的最少的钱数


//多维数组的动态规划，折扣券如何花
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int origin[101];
int discount[101];
int main(){
  int N, X, Y;
  cin >> N; cin >> X; cin >> Y;
  for(auto i=1; i<=N; i++){
    cin >> origin[i];
    cin >> discount[i];
  }
  int f[101][5001][51] = {0};
  
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= X; j++) {
      for (int k = 0; k <= Y; k++) {
        int m = f[i - 1][j][k];
        if (j >= discount[i] 
        && k > 0 
        && f[i - 1][j - discount[i]][k - 1] + 1 > m)

          m = f[i - 1][j - discount[i]][k - 1] + 1;
        if (j >= origin[i] 
        && f[i - 1][j - origin[i]][k] + 1 > m)
                  m = f[i - 1][j - origin[i]][k] + 1;       
        f[i][j][k] = m; //考虑了第i物品，用了j钱，k券购买的物品数
      }
    }  

  }
  for (int i = 0; i <= X; i++)
    if (f[N][X][Y] == f[N][i][Y]) {
      cout << f[N][X][Y];
      cout << " " << i;
      return 0;
    }

}