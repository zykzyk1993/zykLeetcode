/*
 * 451. 根据字符出现频率排序
 * 题意：将字符串内字符重新排序，频率高的放前面
 * 难度：中等
 * 分类：哈希表
 * 算法：模拟即可
 */
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        int max_count = 0;
        for(auto &c:s){
            freq[c]++;
            max_count = max(max_count, freq[c]);
        }
        vector<vector<char>> cnt_char(max_count+1);
        for(auto &p:freq){
            cnt_char[p.second].push_back(p.first);
        }
        string ans;
        for(int i = cnt_char.size()-1;i>=0;i--){
            for(auto &c:cnt_char[i]){
                string temp(i, c);
                ans+=temp;
            }
        }
        return ans;
    }
};
