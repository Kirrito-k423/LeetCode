// 题目描述
// 现在小美获得了一个字符串，小美想要使得这个字符串是回文串.
// 小美找到了你。你可以将字符串中至多两个位置改为任意小写英文字符
// a-z。
// 你的任务是帮小美在当前制约下，获得字典序最小的回文字符串.
// 数据保证能在题目限制下形成回文字符串，
// 注：回文字符串：即一个字答串从前向后和从后向前是完全一致的字符串。
// 例如字符abcba,aaaa,acca都是回文字符串。字符串abcd,acea都不是回文字符串

// 输入描述：
// 一行，一个字答串。字符串中仅由小写英文字符构成
// 保证字符串不会是空字符串。
// 字符串长度介于[1,100000]之间.

// 输出描述：
// 一行，一个在题目条件限制下所可心以获得的字典序最小的回文字符串。

// 分析既然一定有：最多两对不同，
//两对不同,往小改即可
//一对不同，都改成 a
//没不同，第一个非a对改成a

#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
  string str;
  vector<int> diff_pos;
  int diff_cnt = 0;
  cin >> str;
  
  int len = str.length();
  for (int i = 0; i < len >> 1; i++) {
    if (str[i] != str[len - 1 - i]) {
      diff_pos.push_back(i);
      diff_cnt ++;
    }
  }
  
  if (diff_cnt == 2) {
    for (int i = 0; i < diff_pos.size(); i++) {
      int loc1 = diff_pos[i];
      int loc2 = len - 1 - loc1;
      if (str[loc1] < str[loc2]) str[loc2] = str[loc1];
      else str[loc1] = str[loc2];
    }
    cout << str;
    return 0;
  }
  
  if (diff_cnt == 1) {
    int loc = diff_pos[0];
    if (str[loc] != 'a' && str[len - loc - 1] != 'a')
    str[loc] = str[len - loc - 1] = 'a';
    else {
      str[loc] = str[len - loc - 1] = 'a';
      str[len / 2] = 'a';
    }
    cout << str;
    return 0;
  }
  
  if (diff_cnt == 0) {
    for (int i = 0; i < len / 2; i ++) {
      if (str[i] != 'a') {
        str[i] = str[len - 1 - i] = 'a';
        break;
      }
    }
    cout << str;
    return 0;
  }
}