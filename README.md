# LeetCode


## ACM模式

大厂常用模式，不同于LC的核心代码模式，需要终端写输入输出，和全部头文件 

可以在 codefun2000.com 和 [牛客](https://www.nowcoder.com/exam/oj/ta?tpId=37&fromPut=pc_newmedia_zhihu_HJ)上多练习

23年3月18日， 美团后端机试

## need to debug
use gdbgui


## Leetcode debug

参考[文章](https://blog.csdn.net/zhangpeterx/article/details/88775434)，LC不会显示，可以本地调试，会具体显示错误在哪一行
```bash
g++ -O -g -fsanitize=address  test.cpp
./a.out
=================================================================
==4012331==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x60200000000c at pc 0x5570841f9c65 bp 0x7ffe3e15cb80 sp 0x7ffe3e15cb70
READ of size 4 at 0x60200000000c thread T0
    #0 0x5570841f9c64 in Solution::makeArrayIncreasing(std::vector<int, std::allocator<int> >&, std::vector<int, std::allocator<int> >&) /staff/shaojiemike/github/LeetCode/1001-1500/1187/1187.cpp:36
```

## 大厂笔试网站以及考试说明

* [华为](https://shixizhi.huawei.com/iexam/helpCenter.html#/examGuide/index)
  * 考试全程请不要跳出考试页面（编程类题允许离开页面使用本地IDE），前三次切换会有弹窗提示，之后将不再提示但会后台记录。不要使用或访问任何与考试无关的网页、搜索、聊天工具；
  * 好像没有强制类型转换？

要将一个十进制数 $x$ 转换为负 $n$ 进制表示，我们可以使用除法和取余运算，具体步骤如下：

1. 对 $x$ 进行除法和取余运算，得到商 $q_1$ 和余数 $r_1$，使得 $x = q_1 \times n - r_1$，其中 $0 \leq r_1 < n$。
2. 如果 $r_1$ 为负数，则将其加上 $n$，得到一个非负的余数 $r_2 = r_1 + n$，并将商 $q_2$ 加上 1，使得 $x = q_2 \times n - r_2$。
3. 如果 $q_2$ 不为 0，则重复步骤 1 和 2，将 $q_2$ 进行除法和取余运算，得到商 $q_3$ 和余数 $r_3$，使得 $q_2 = q_3 \times n - r_3$，并判断 $r_3$ 是否为负数，如果是，则将其加上 $n$，依此类推，直到得到的商为 0。

最后，将所有的余数按照从后往前的顺序排列，就得到了输入数 $x$ 的负 $n$ 进制表示。例如，要将十进制数 $-10$ 转换为负 $3$ 进制表示，可以按照如下的步骤进行计算：

- $-10 \div 3 = -3 \cdots 1$，余数为 $1$，商为 $-3$。
- $-3 \div 3 = -1 \cdots 0$，余数为 $0$，商为 $-1$。
- $-1 \div 3 = 0 \cdots -1$，余数为 $2$，加上 $3$ 得到 $r_3 = 2$，商为 $0$。
- 因此，$-10$ 的负 $3$ 进制表示为 $-1012$。