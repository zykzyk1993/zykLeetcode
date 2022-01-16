/*
 * 165. 比较版本号
 * 题意：给定两个字符串版本号，比较大小，1.0和1.0.0视为一样
 * 难度：中等
 * 分类：字符串 模拟
 * 算法：分成int数组保存，然后逐个比较
 */
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        int cur = 0;
        for(auto &c:version1) {
            if (c == '.') {
                v1.push_back(cur);
                cur = 0;
            }
            else {
                cur = cur * 10 + (c - '0');
            }
        }
        v1.push_back(cur);
        cur = 0;
        for(auto &c:version2) {
            if (c == '.') {
                v2.push_back(cur);
                cur = 0;
            }
            else {
                cur = cur * 10 + (c - '0');
            }
        }
        v2.push_back(cur);
        int s1 = v1.size(), s2 = v2.size();
        for(int i = 0; i < min(s1, s2); i ++) {
            if (v1[i] < v2[i]) {
                return -1;
            }
            if (v1[i] > v2[i]) {
                return 1;
            }
        }
        if(s1 > s2) {
            for (int i = s2; i < s1; i ++) {
                if (v1[i] != 0) {
                    return 1;
                }
            }
        }
        if(s2 > s1) {
            for (int i = s1; i < s2; i ++) {
                if (v2[i] != 0) {
                    return -1;
                }
            }
        }
        return 0;
    }
};
