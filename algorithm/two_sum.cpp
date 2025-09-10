//问题描述：给了
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
//原理：key --> 哈希函数 --> hash值
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> phonebook; // key=名字(string)，value=号码(int)

    // 插入数据
    phonebook["小红"] = 12345;
    phonebook["小明"] = 67890;

    // 查找
    cout << "小红的号码是: " << phonebook["小红"] << endl;

    // 判断是否存在
    if(phonebook.find("小明") == phonebook.end()) {
        cout << "小明不在电话簿里" << endl;
    }

    return 0;
}