/*
 * 43. 字符串相乘
 * 题意：大数乘法 字符串表示
 * 难度：中等
 * 分类：字符串 模拟
 * 算法：使用vector来保存结果的每一位，翻转字符串，对于两个数的i和j位，会作用于结果的第i+j位，最终统计结果时再统一进位
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        // 翻转
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int m = num1.size(), n = num2.size();
        vector<int> res(m + n, 0);
        // 对应位保存至res的对应位置 可以超过10
        for(int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                int n1 = num1[i] - '0';
                int n2 = num2[j] - '0';
                int temp = n1 * n2;
                res[i+j] += temp;
            }
        }
        // 统一进位
        for(int i = 0; i < res.size() - 1; i ++) {
            if (res[i] >= 10) {
                res[i+1] += res[i]/10;
                res[i] = res[i] % 10;
            }
        }
        // 翻转输出结果
        reverse(res.begin(), res.end());
        string ans;
        for(int i = 0; i < res.size(); i ++) {
            if (i == 0 && res[i] == 0) {
                continue;
            }
            ans += char(res[i] + '0');
        }
        return ans;
    }
};
