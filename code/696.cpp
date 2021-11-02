/*
 * 696. 计数二进制子串
 * 题意：计算相同的连续1和0的组数
 * 难度：简单
 * 分类：数组
 * 算法：保存0和1的个数，然后遍历，每个相邻的取最小，最小有几个就加上几组
 */
class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> counts;
        int ptr = 0, n = s.size();
        while (ptr < n) {
            char c = s[ptr];
            int count = 0;
            while (ptr < n && s[ptr] == c) {
                ++ptr;
                ++count;
            }
            counts.push_back(count);
        }
        int ans = 0;
        for (int i = 1; i < counts.size(); ++i) {
            ans += min(counts[i], counts[i - 1]);
        }
        return ans;
    }
};
