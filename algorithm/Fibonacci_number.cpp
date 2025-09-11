//Way 1:迭代法
class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;   // 处理 n=0 或 n=1 的情况
        int a = 0, b = 1;      // a = F(0), b = F(1)
        for (int i = 2; i <= n; i++) {
            int c = a + b;     // 当前结果
            a = b;             
            b = c;
        }
        return b;              // 最后 b 就是 F(n)
    }
};
//Way 2:递归法
class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;   // 基础情况 F(0) = 0
        if (n == 1) return 1;   // 基础情况 F(1) = 1
        return fib(n - 1) + fib(n - 2); // 一直递归
    }
};