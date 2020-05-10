/*
 * 771. 宝石与石头
 * 字符串中字符种类
 * 难度：简单
 * 分类：哈希 模拟
 * 算法：简单模拟
 */
class Solution {
public:
    int numJewelsInStones(string J, string S)
    {
        unordered_map<char, bool> mp;
        int sum = 0;
        for (auto j : J)
            mp[j] = 1;
        for (auto s : S)
            if (mp[s]) sum++;
        return sum;
    }
};
