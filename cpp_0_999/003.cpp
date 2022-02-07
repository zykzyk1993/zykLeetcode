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

// 官方题解
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 哈希集合，记录每个字符是否出现过
        unordered_set<char> occ;
        int n = s.size();
        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为 -1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // 不断地移动右指针
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};
