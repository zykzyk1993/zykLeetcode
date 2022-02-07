/*
 * 49. 字母异位词分组
 * 题意：相同字母组合的字符串分到一个组里
 * 难度：中等
 * 分类：哈希表 字符串
 * Tips：思路很直接，用map即可
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> m;
        for(string str:strs){
            string temp=str;
            sort(str.begin(),str.end());
            m[str].push_back(temp);
        }
        unordered_map<string,vector<string>>::iterator iter;
        for(iter=m.begin();iter!=m.end();iter++){
            ans.push_back(iter->second);
        }
        return ans;
    }
};
