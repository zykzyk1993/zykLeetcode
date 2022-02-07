/*
 * 6. Z 字形变换
 * 题意：对给定字符串，以从上往下、从左到右进行 Z 字形排列
 * 难度：中等
 * 分类：模拟 字符串
 * 算法：采用字符串数组存储每行字符串，最终模拟遍历
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> s_in_rows(numRows, "");
        int group_size = numRows * 2 - 2;
        for(int i = 0; i < s.size(); i++) {
            int group_idx = i % group_size;
            if(group_idx > group_size / 2) {
                group_idx = group_size - group_idx;
            }
            s_in_rows[group_idx] += s[i];
        }
        string res = "";
        for (auto &sub_str:s_in_rows){
            res += sub_str;
        }
        return res;
    }
};
