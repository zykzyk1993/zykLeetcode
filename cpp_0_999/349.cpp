/*
 * 349. 两个数组的交集
 * 题意：求两个数组公共的元素，不用考虑顺序
 * 难度：简单
 * 分类：哈希 双指针
 * 算法：用集合保存，或者排序后双指针
 */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        vector<int> res;
        for(auto &c:nums1) {
            s.insert(c);
        }
        for(auto &c:nums2) {
            if (s.count(c)) {
                res.push_back(c);
                s.erase(c);
            }
        }
        return res;
    }
};
