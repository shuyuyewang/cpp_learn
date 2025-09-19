#include <iostream>
#include <vector>
#include <deque>   // 用到 deque 也要加
using namespace std;
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
            // 2. 保证队列单调递减
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            // 3. 入队当前元素下标
            dq.push_back(i);
            // 4. 当窗口形成时，记录最大值
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