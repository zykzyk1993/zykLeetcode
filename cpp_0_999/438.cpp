/*
 * 438. 找到字符串中所有字母异位词
 * 给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
 * 难度：中等
 * 分类：滑动窗口
 * 算法：使用滑动窗口计数
 */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> cnt_p(26,0);
        vector<int> cnt_s(26,0);
        for(auto c:p){
            cnt_p[c-'a']++;
        }
        int satisfy=0,n=p.size();
        if(s.size()<n)return ans;
        for(int i=0;i<s.size();i++){
            if(i>=n){
                if(cnt_s[s[i-n]-'a']<=cnt_p[s[i-n]-'a'])satisfy--;
                else satisfy++;
                cnt_s[s[i-n]-'a']--;
            }
            if(cnt_s[s[i]-'a']>=cnt_p[s[i]-'a'])satisfy--;
            else satisfy++;
            cnt_s[s[i]-'a']++;
            if(satisfy==n)ans.push_back(i+1-n);
        }
        return ans;
    }
};
