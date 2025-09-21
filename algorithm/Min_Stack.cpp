class MinStack {
private:
    stack<int> s;
    stack<int> minS;
public:
    MinStack() {}

    void push(int val) {
        s.push(val);
        //如果辅助栈是空的（说明第一次压栈）
        // 或者 val 比当前的最小值更小
        // 就把 val 压到 minS 里
        if (minS.empty() || val <= minS.top()) {
            minS.push(val);
        } else {
            //如果 val 不是更小的值，那么就把 当前最小值再压一遍。
            //这样保证主栈 s 和辅助栈 minS 的高度一样。
            //当你之后 pop 时，两个栈一起弹出，就能保持最小值记录和主栈同步
            minS.push(minS.top()); // 保持同步，保证 O(1) 查询
        }
    }

    void pop() {
        s.pop();
        minS.pop();//保持同步
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minS.top();
    }
};
