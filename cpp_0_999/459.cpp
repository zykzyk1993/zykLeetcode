/*
 * 459. 重复的子字符串
 * 题意：判断一个字符串是否可以通过某个子串重复多次构成
 * 难度：简单
 * 分类：字符串
 * 算法：模拟，在整除的情况下看子串是否相等
 */
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i = 2; i <= n; i ++) {
            if (n % i != 0) {
                continue;
            }
            string s1 = s.substr(0, n / i);
            bool flag = true;
            for (int j = 1; j < i; j ++) {
                string s2 = s.substr(j * n / i, n / i);
                if (s1 != s2) {
                    flag = false;
                    break;
                }
            }
            if (flag) return true;
        }
        return false;
    }
};
