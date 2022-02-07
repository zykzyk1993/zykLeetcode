/*
 * 205. 同构字符串
 * 题意：判断是否一个字符串能否通过一对一字符映射转换为另一个字符串
 * 难度：简单
 * 分类：字符串 哈希表
 * 算法：使用两个哈希表保存正向反向映射，然后按照题意模拟
 */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char, char> ts, st;
        for(int i = 0; i < s.size(); i ++){
            if(st.count(s[i])){ //之前见过的字符
                if(st[s[i]] != t[i] || ts[t[i]] != s[i]){
                    return false;
                }
            }else{
                if(ts.count(t[i]) && ts[t[i]] != s[i]){
                    return false;
                }
                st[s[i]] = t[i];
                ts[t[i]] = s[i];
            }
        }
        return true;
    }
};
