/*
 * 179. 最大数
 * 题意：组合拼接数组中的使最终的数字最大
 * 难度：中等
 * 分类：数组 排序
 * 算法：设计排序比较函数，转化为字符串后看哪种组合方式更大
 */
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int &num1, const int &num2) {
            string s1 = to_string(num1);
            string s2 = to_string(num2);
            return (s1+s2) > (s2+s1);
        });
        string ans;
        for(auto &num:nums) {
            ans += to_string(num);
        }
        int start = 0;
        while(start < ans.size() - 1 && ans[start] == '0') {
            start ++;
        }
        return ans.substr(start);
    }
};
