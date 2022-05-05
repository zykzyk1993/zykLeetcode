/*
 * 806. 写字符串需要的行数
 * 题意：给定每个字符所需宽度，宽度超过100需要另起一行，求总共需要多少行
 * 难度：简单
 * 分类：模拟
 * 算法：模拟，超过100行则另起
 */
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int sum = 0;
        vector<int> res = {1, 0};
        for(auto &c:s) {
            if (sum + widths[c-'a'] <= 100) {
                sum += widths[c-'a'];
            }
            else {
                res[0] ++;
                sum = widths[c-'a'];
            }
        }
        res[1] = sum;
        return res;
    }
};
