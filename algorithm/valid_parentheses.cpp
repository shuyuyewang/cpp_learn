/*
//感觉逻辑很像俄罗斯方块，消消乐这种，所以要用到堆栈的结构，先进后出
if (是左括号) {
    // 放到栈里，等待配对
    st.push(c);
} else {
    // 遇到右括号，尝试“消掉”一对
    if (st.top() 和 c 匹配) {
        st.pop(); // 成功消掉一对
    } else {
        return false; // 消不掉，失败
    }
}
*/
class Solution {
public:
    bool isValid(const string& s) {
        // 奇数长度肯定不合法
        if (s.size() % 2 != 0) 
            return false;

        stack<char> st;
        for (char c : s) {
            // 左括号直接入栈
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                // 遇到右括号，先检查栈是否为空
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                // 栈顶必须与当前右括号匹配
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    return false;
                }
            }
        }
       
        return st.empty(); // 最后栈必须清空才算通关
    }
};