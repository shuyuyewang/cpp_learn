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

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // mp 用来存储「前缀和」出现的次数
        // key: 前缀和的值
        // value: 该前缀和出现的次数
        unordered_map<int,int> mp;

        mp[0] = 1;  
        // 初始化：前缀和 = 0 出现过 1 次
        // 作用：处理「从下标 0 开始的子数组」刚好等于 k 的情况

        int prefix = 0;  // 当前前缀和
        int ans = 0;     // 统计答案

        for (int x : nums) {
            prefix += x;  // 更新前缀和

            // 如果之前有 prefix-k 的前缀和，
            // 说明当前子数组和 = k
            if (mp.count(prefix - k)) {
                ans += mp[prefix - k];  // 累加所有可能的子数组
            }

            // 记录当前前缀和的出现次数
            mp[prefix]++;
        }

        return ans;
    }
};
