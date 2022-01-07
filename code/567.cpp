/*
 * 567. 字符串的排列
 * 题意：写一个函数来判断 s2 是否包含 s1 的排列
 * 难度：中等
 * 分类：字符串 滑动窗口
 * 算法：用diff记录相差的字符串数量，滑动窗口动态更新，如果diff为0则返回true，否则最后返回false
 */

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        if (m > n) return false;
        vector<int> cnt(26, 0);
        for (int i = 0; i < m; i ++) {
            cnt[s1[i] - 'a'] ++;
            cnt[s2[i] - 'a'] --;
        }
        int diff = 0;
        for (int c:cnt) {
            if (c != 0) {
                diff ++;
            }
        }
        if (diff == 0) return true;
        for (int i = m; i < n; i ++) {
            int next = s2[i] - 'a', prev = s2[i - m] - 'a';
            if (cnt[next] == 0) {
                diff ++;
            }
            cnt[next] --;
            if (cnt[next] == 0) {
                diff --;
            }

            if (cnt[prev] == 0) {
                diff ++;
            }
            cnt[prev] ++;
            if (cnt[prev] == 0) {
                diff --;
            }
            if (diff == 0) {
                return true;
            }
        }
        return false;
    }
};
