/*
 * 409. 最长回文串
 * 题意：给定一个字符串，求所有字符能构成的最长回文串
 * 难度：简单
 * 分类：字符串
 * 算法：所有字符串频次整除2，最后可以多加一个字符放正中间
 */
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;
        for(auto &c:s){
            m[c]++;
        }
        int ans = 0;
        for(auto &p:m){
            ans += p.second / 2 * 2;
        }
        if(ans < s.size()) ans ++;
        return ans;
    }
};
