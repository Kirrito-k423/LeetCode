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


