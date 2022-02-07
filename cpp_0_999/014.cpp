/*
 * 14. 最长公共前缀
 * 题意：找出给定字符串数组的公共前缀
 * 难度：简单
 * 分类：字符串
 * 算法：排序后可以直接对比最前最后的
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        sort(str.begin(),str.end());
        string &s1=str.front();
        string &s2=str.back();
        int i=0;
        while(i<s1.size()&&i<s2.size()&&s1[i]==s2[i]){
            ++i;
        }
        return string(s1.begin(),s1.begin()+i);
    }
};
