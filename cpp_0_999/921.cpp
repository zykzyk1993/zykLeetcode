/*
 * 921. 使括号有效的最少添加
 * 题意：给定括号字符串，要使其合法，最少添加多少字符
 * 难度：中等
 * 分类：贪心
 * 算法：从左往右遍历缺少的左括号数量，从右往左遍历缺少的右括号数量，两者相加
 * 或者直接一遍遍历，保存缺少的左括号数量，和最后多余的左括号数量
 */
class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0, res = 0;
        for (auto &c:s) {
            if (c == '(') {
                balance ++;
            }
            else {
                if (balance > 0) {
                    balance --;
                }
                else {
                    res ++;
                }
            }
        }
        return balance + res;
    }
};

class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0, n = s.size(), res = 0;
        for(int i = 0; i < n; i ++) {
            if (s[i] == '(') {
                balance ++;
            }
            else {
                if (balance <= 0) {
                    res ++;
                }
                else {
                    balance --;
                }
            }
        }
        balance = 0;
        for(int i = n - 1; i >= 0; i --) {
            if (s[i] == ')') {
                balance ++;
            }
            else {
                if (balance <= 0) {
                    res ++;
                }
                else {
                    balance --;
                }
            }
        }
        return res;
    }
};
