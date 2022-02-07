/*
* 28. 实现 strStr()
* 题意：查找指定子串位置，不存在返回-1
* 难度：简单(kmpf困难)
* 分类：字符串
* 算法：暴力算法，KMP算法
*/

//暴力模拟
class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size(), n = needle.size();
        if (n == 0)
            return 0;
        for(int i = 0; i <= h - n; i++) {
            if (haystack.substr(i, n) == needle)
                return i;
        }
        return -1;
    }
};

//KMP
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) {
            return 0;
        }
        vector<int> pi(m);
        for (int i = 1, j = 0; i < m; i++) {
            while (j > 0 && needle[i] != needle[j]) {
                j = pi[j - 1];
            }
            if (needle[i] == needle[j]) {
                j++;
            }
            pi[i] = j;
        }
        for (int i = 0, j = 0; i < n; i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = pi[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == m) {
                return i - m + 1;
            }
        }
        return -1;
    }
};
