class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        // 定义一个队列，存储当前还在排队的人的下标
        queue<int> q;
        for (int i = 0; i < tickets.size(); ++i) {
            q.push(i); // 一开始所有人都在队列中
        }
        int time = 0; 
        // 当队列不为空时，说明还有人没买完票
        while (!q.empty()) {
            // 取出队首（当前买票的人）
            int i = q.front();
            q.pop();

            // 花费 1 秒，这个人买 1 张票
            ++time;
            --tickets[i];

            // 如果他还没买完票，就重新排到队尾
            if (tickets[i] > 0) {
                q.push(i);
            }

            // 如果他正好是第 k 个人，并且买完了
            // 那么这时就是答案
            if (i == k && tickets[i] == 0) {
                return time;
            }
        }
        return time;
    }
};
