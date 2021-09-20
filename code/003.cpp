/*
 * 3. 无重复字符的最长子串
 * 题意：给定一个字符串，找出其中不含有重复字符的最长子串的长度
 * 难度：中等
 * 分类：哈希表，模拟
 * 算法：使用hash表来记录字符最后一次出现的位置，left保存字串的左起始位置
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0)return 0;
        int maxLen=1,left=0;
        unordered_map<char,int> m;
        m[s[0]]=0;
        for(int i=1;i<n;i++){
            if(m.count(s[i])&&m[s[i]]>=left){
                left=m[s[i]]+1;
            }
            maxLen=max(maxLen,i-left+1);
            m[s[i]]=i;
        }
        return maxLen;
    }
};

//2021
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m_left_idx; //当前字符最靠右的idx,用来计算子串长度
        int max_len = 0, cur_left_bound = 0;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if (m_left_idx.count(c) > 0 && m_left_idx[c] >= cur_left_bound){
                cur_left_bound = m_left_idx[c] + 1;
            }
            max_len = max(max_len, i - cur_left_bound + 1);
            m_left_idx[c] = i;
        }
        return max_len;
    }
};
