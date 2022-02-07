/*
 * 242. 有效的字母异位词
 * 题意：判断是否两个词中每个字母出现频率相等
 * 难度：简单
 * 分类：字符串
 * 算法：遍历，一个加频次，一个减频次
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        vector<int> cnt(26, 0);
        for(int i = 0; i < s.size(); i ++){
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; i ++){
            if(cnt[i] != 0){
                return false;
            }
        }
        return true;
    }
};
