/*
 * 316. 去除重复字母
 * 题意：删除字符串中的重复字母，使字典序最小，且相对顺序不变
 * 难度：中等
 * 分类：栈 贪心
 * 算法：遍历时，记录每个字符剩余的个数。遇到新字符则插入，然后栈中字符，若字典序大于该字符，且后续还有，则弹出
 */
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26, 0);
        vector<bool> in_str(26, false);
        for(auto &c:s){
            cnt[c-'a']++;
        }
        string res;
        for(auto &c:s){
            cnt[c-'a']--;
            while(!in_str[c-'a'] && !res.empty() && res.back() > c && cnt[res.back()-'a'] > 0) {
                in_str[res.back()-'a'] = false;
                res.pop_back();
            }
            if(!in_str[c-'a']){
                in_str[c-'a'] = true;
                res.push_back(c);
            }
        }
        return res;
    }
};
