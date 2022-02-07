/*
 * 402. 移掉 K 位数字
 * 题意：将一个数中的K个数字移除，求移除后最小的数字
 * 难度：中等
 * 分类：贪心 单调栈
 * 算法：使用单调栈保持递增，如果遇到递减的数字，删除前一个，直到删除完成，若遍历完未删除完成，则从末尾补删
 */
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (k == n) {
            return "0";
        }
        string res;
        vector<char> s;
        for(auto &c:num) {
            while(!s.empty() && s.back() > c && k) {
                s.pop_back();
                k--;
            }
            s.push_back(c);
        }
        while(k--) {
            s.pop_back();
        }
        bool lead_zero = true;
        for(auto &c:s) {
            if (lead_zero && c == '0') {
                continue;
            }
            lead_zero = false;
            res += c;
        }
        return res == "" ? "0" : res;
    }
};
