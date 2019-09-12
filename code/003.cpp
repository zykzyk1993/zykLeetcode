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
