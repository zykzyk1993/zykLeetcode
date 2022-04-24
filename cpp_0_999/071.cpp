/*
 * 71. 简化路径
 * 题意：简化. .. / 按照指定格式返回
 * 难度：中等
 * 分类：模拟 字符串
 * 算法：模拟即可，注意细节
 */
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> res;
        string cur;
        for (auto &c:path) {
            if (c == '/') {
                if (cur.empty() || cur == ".") {
                    cur = "";
                    continue;
                }
                else if (cur == "..") {
                    if (!res.empty()) {
                        res.pop_back();
                    }
                }
                else {
                    res.push_back(cur);
                }
                cur = "";
            }
            else {
                cur += c;
            }
        }
        if (!cur.empty() && cur != "."){
            if (cur == "..") {
                if (!res.empty()) {
                    res.pop_back();
                }
            }
            else {
                res.push_back(cur);
            }
        }
        if (res.empty()) {
            return "/";
        }
        string ans;
        for (auto &s:res) {
            ans = ans + "/" + s;
        }
        return ans;
    }
};
