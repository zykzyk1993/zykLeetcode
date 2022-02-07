/*
 * 93. 复原 IP 地址
 * 题意：从字符串中，加入.复原合法IP地址
 * 难度：中等
 * 分类：dfs
 * 算法：dfs，判断是否能加.或者必须加. 同时记录当前number
 */
class Solution {
public:
    vector<string> res;
    void dfs(string &s, string cur, int cur_idx, int dot_num, int cur_num) {
        if(cur_idx == s.size()) {
            if (dot_num == 3) {
                res.push_back(cur);
            }
            return;
        }
        int cur_digit = s[cur_idx] - '0';
        if(cur_num == 0 && cur.back() == '0') { // 单独的0
            dfs(s, cur + ".", cur_idx, dot_num + 1, 0);
            return;
        }
        if(dot_num < 3 && cur.size() > 0 && cur.back() != '.') {
            dfs(s, cur + ".", cur_idx, dot_num + 1, 0);
        }
        cur_num = cur_num * 10 + cur_digit;
        if(cur_num <= 255) {
            dfs(s, cur + s[cur_idx], cur_idx + 1, dot_num, cur_num);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        dfs(s, "", 0, 0, 0);
        return res;
    }
};
