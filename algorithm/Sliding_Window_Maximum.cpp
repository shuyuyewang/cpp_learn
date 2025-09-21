#include <iostream>
#include <vector>
#include <deque> 
using namespace std;
//存下标，队列里数值必须保持单调递减。
//新元素入队时
//如果它比队尾大，就把队尾踢掉，继续比，直到比不过为止。
//这样一来，队列里永远只剩“可能成为未来最大值的候选人”。
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // 存储下标，维护单调递减队列，方便比较大小
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); i++) {
            // 确保队头在窗口范围内
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            // 保证队列单调递减
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            // 入队当前元素下标
            dq.push_back(i);
            // 当窗口形成时，记录最大值
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> res = sol.maxSlidingWindow(nums, k);
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;
}