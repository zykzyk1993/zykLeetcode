/*
 * 392. 判断子序列
 * 题意：判断 s 是否为 t 的子序列
 * 难度：简单
 * 分类：模拟
 * 算法：
 */
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sp = 0, tp = 0;
        while(sp < s.size() && tp < t.size()){
            if(s[sp] == t[tp]){
                sp ++;
            }
            tp ++;
        }
        return sp == s.size();
    }
};
