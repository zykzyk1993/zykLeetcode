/*
 * 710. 黑名单中的随机数
 * 题意：给定一批数组和黑名单，随机从剩余数字中取数字，尽量少调用random函数
 * 难度：困难
 * 分类：数组 哈希表
 * 算法：保存白名单数字长度，将长度范围内的黑名单数字映射到剩余的白名单数字，然后直接random即可
 */
class Solution {
public:
    unordered_map<int, int> m;
    int white = 0;
    Solution(int n, vector<int>& blacklist) {
        white = n - blacklist.size(); // 白名单数字数量
        unordered_set<int> s(blacklist.begin(), blacklist.end());
        for(auto &b:blacklist) {
            if(b >= min(white, n)) { // 大于n或大于白名单数量的不做处理
                continue;
            }
            while(s.count(n-1)) { // 属于黑名单的不映射
                n--;
            }
            m[b] = n-1; // 将该黑名单位置映射到末尾的白名单位置
            n--; // 下一次映射查找的末尾位置-1
        }
    }
    
    int pick() {
        int idx = rand() % white;
        return m.count(idx) == 0?idx:m[idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
