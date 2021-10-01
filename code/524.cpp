/*
 * 524. 通过删除字母匹配到字典里最长单词
 * 题意：删除最少的字符能得到字典中的字符串
 * 难度：中等
 * 分类：字符串 双指针
 * 算法：先按照要求排好序，然后逐个判断是否为子串
 */
bool cmp(string &a, string &b){
    if(a.size()==b.size()){
        return a<b;
    }
    return a.size()>b.size();
}
class Solution {
public:
    bool isSub(const string &s, const string &p){
        int i=0, j=0;
        while(i<s.size()&&j<p.size()){
            if(s[i]==p[j]){
                j++;
            }
            i++;
        }
        return j>=p.size();
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), cmp);
        for(auto &c:dictionary){
            if(isSub(s, c)){
                return c;
            }
        }
        return "";
    }
};
