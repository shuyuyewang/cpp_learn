//Way 1：暴力法
//双循环逐个匹配，思路简单但是匹配比较慢
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();//提取动态数组大小
        for (int i = 0; i < n; i++) {//第一轮循环
            for (int j = i + 1; j < n; j++) {  //第二轮循环，j 从 i+1 开始
                if (nums[i] + nums[j] == target) {
                    return {i, j};  
                }
            }
        }
        return {}; 
    }
};
*/
//Way 2: 哈希表
//感觉和python里面的字典的用法差不多，键值对匹配即可
//原理：key --> 哈希函数（一种压缩映射的思想） --> hash值  --> 对应的容器
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;  // // 哈希表的键值对 (key, value)
        for (int i = 0; i < nums.size(); i++) {//开始遍历下标
            int need = target - nums[i];  // 需要找的另一个数
            if (mp.find(need) != mp.end()) {//找到了则返回
                return {mp[need], i};
            }
            // 没找到则把当前数的键值对存入哈希表
            mp[nums[i]] = i;
        }
        return {}; 
    }
};