#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int X[501];
int Y[501];

int main(){
  int N, A, B;
  cin >> N;
  cin >> A;
  cin >> B;
  for(int i=0; i<N; i++){
    cin >> X[i];
    cin >> Y[i];
  }
  int ans = 0;
  for (int stx = 1; stx <= 1000; stx++) {
  for (int sty = 1; sty <= 1000; sty++) {
    int cnt = 0;
    for (int j = 0; j < N; j++) {
      if (X[j] - stx >= 0 && X[j] - stx <= A && Y[j] - sty >= 0 && Y[j] - sty <= B)
        cnt ++;
    }
    if (cnt > ans) ans = cnt;
  }
  }
  cout << ans << endl;
}


// 请写出下面问题的C++代码 题目描述： 小美在玩一项游戏。该游戏的目标是尽可能抓获敌人。 
// 敌人的位置将被一个二维坐标（x，y)所描述： 小美有一个全屏技能，技能能一次性将若干敌人一次性捕获： 捕获的敌人之间的横坐标的最大差值不能大于A,纵坐标的最大差值不能大于B。 
// 现在给出所有敌人的坐标，你的任务是计算小美一次性最多能使用技能捕获多少敌人。 
// 输入描述：第一行三整数N、A、B,表示共有N个敌人，小美的全屏技能的参数A和参数B。 接下来行，每行两个数字x、y, 描述一个敌人所在的坐标。
//  1≤N≤500，≤A,B≤1000,1<x,y<1000。
//   输出：一行，一个整数表示小美使用技能单次所可以捕获的最多数量，

// 解法思路：数据集小，直接暴力遍历所有可能点，复杂度O(1000*1000*500)
//          最多 -> max（组合）
// chatGPT 解法： 暴力所有点的组合，至少有2个点，复杂度O(N^3)

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    int x[n], y[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    int maxEnemies = 1;  // 最少捕获一个敌人
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // 计算两个敌人之间的距离
            int dx = abs(x[i] - x[j]);
            int dy = abs(y[i] - y[j]);

            // 判断两个敌人之间的距离是否符合技能要求
            if (dx <= a && dy <= b) {
                // 统计技能范围内的敌人数量
                int count = 2;  // 至少捕获两个敌人
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;
                    if (abs(x[k] - x[i]) <= a && abs(y[k] - y[i]) <= b &&
                        abs(x[k] - x[j]) <= a && abs(y[k] - y[j]) <= b) {
                        count++;
                    }
                }
                maxEnemies = max(maxEnemies, count);
            }
        }
    }

    cout << maxEnemies << endl;
    return 0;
}

// 解释：
// 首先读入输入，然后使用两重循环遍历所有可能的敌人对，计算它们之间的距离，并判断是否符合技能要求
// （横坐标的最大差值不能大于A，纵坐标的最大差值不能大于B）。如果符合要求，则统计在技能范围内的敌人数量，
// 更新最大值。最后输出最大值即可。