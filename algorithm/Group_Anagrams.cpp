#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // map 的 key 是“字母频率编码后的字符串”，value 是同组的原字符串列表
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            //  统计 26 个小写字母的出现次数
            int cnt[26] = {0};
            for (char c : s) {
                // 题目默认小写字母
                cnt[c - 'a']++;
            }

            //    设计键，把频率数组序列化成一个字符串
            //    例如 "aab" -> "#2#1#0#0...#0"
            string key;
            for (int i = 0; i < 26; ++i) {
                key.push_back('#');
                key += to_string(cnt[i]);
            }

            // 将原串放入对应组
            mp[key].push_back(s);
        }

        // 收集答案
        vector<vector<string>> ans;
        ans.reserve(mp.size());
        for (auto &p : mp) ans.push_back(p.second);
        return ans;
    }
};
