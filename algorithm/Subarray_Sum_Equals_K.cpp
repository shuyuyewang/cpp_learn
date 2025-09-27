class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = (int)nums.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int sum = 0;                 // 累加 nums[i到j]
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                if (sum == k) ++ans;
            }
        }
        return ans;
    }
};
