/*
 * 496. 下一个更大元素 I
 * 题意：给定两个数组，求数组1元素在数组2中下一个更大的元素
 * 难度：简单
 * 分类：单调栈
 * 算法：单调栈计算，用哈希表保存结果
 */
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> m;
        for(int i = 0; i < nums2.size(); i ++){
            while(!s.empty() && s.top() < nums2[i]){
                m[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        vector<int> res;
        for(auto &num1:nums1){
            res.push_back(m.count(num1)?m[num1]:-1);
        }
        return res;
    }
};
