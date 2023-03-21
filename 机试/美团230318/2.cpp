// 题目描述：
// 小美现在有一串彩带，假定每一厘米的彩带上都是一种色彩，
// 因为任务的需要，小美希望从彩带上截取一段，使得彩带中的颜色数量不超过K种！
// 显然，这样的截取方法可能非常多。于是小美决定尽量长地截取一段
// 你的任务是帮助小美截取尽量长的一段，使得这彩带上不同的色彩数量不超过K种
// 输入描述：
// 第一行两个整数N、K，以空格分开，分别表示彩带有N厘米长，你截取的一段连续的彩带不超过
// K种颜色
// 接下来一行N个整数，每个整数表示一种色彩，相间的整数表示相同的色彩
// 1≤N,K≤5000，彩带上的颜色数字[1,2000]之间，
// 输出描述
// 一行，一个整数，表示选取的彩常的最大长度

//就是模拟，左边添加，右边减去，需要记录出现的各自颜色的各自的次数

#include <cstdio>
#include <cstdlib>
#include <vector>

int main() {
  int n, k;
  int a[5001];
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  // count lastest position
  int cnt[2001]; //记录颜色最后出现位置，如果在[left,right]之间
  for (int i = 0; i < 2001; i++) {
    cnt[i] = 5001;
  }
  int maxlen = 1;
  int head = 0;
  cnt[a[0]] = 0;
  int col = 1;
  for (int i = 1; i < n; i++) {
    if (cnt[a[i]] == 5001) {
      // color a[i] not in seq
      if (col < k) {
        col++;
      }
      else {
        // color == k
        // find subsitution 寻找踢出去的
        int sub = 0;
        for (int j = 0; j < 2001; j++) {
          if (cnt[j] < cnt[sub]) {
            sub = j;
          }
        }
        head = cnt[sub] + 1;
        cnt[sub] = 5001;
      }
    }
    cnt[a[i]] = i;
    if (i - head + 1 > maxlen)
      maxlen = i - head + 1;
  }
  printf("%d\n", maxlen);
  return 0;
}

//chatGPT -3.5
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 5005;
int a[MAXN], cnt[MAXN];

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int ans = 0, tot = 0, l = 1, r = 0;
    while (l <= n) {
        while (r < n && (tot < k || cnt[a[r+1]])) {
            r++;
            if (!cnt[a[r]]) tot++;
            cnt[a[r]]++;
        }
        ans = max(ans, r - l + 1);
        cnt[a[l]]--;
        if (!cnt[a[l]]) tot--;
        l++;
    }
    cout << ans << endl;

    return 0;
}
