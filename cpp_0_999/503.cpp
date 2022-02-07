/*
 * 503. 下一个更大元素 II
 * 题意：整个数组是循环的，求每个元素的下一个更大的数，如果没有返回-1
 * 难度：中等
 * 分类：单调栈
 * 算法：使用单调栈按照递减顺序，对于数组首尾相连，则不清空栈，再从头遍历一次，此时可以更新值为-1(第一遍未更新)的结果值
 */
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> s;
        for(int i = 0; i < n; i ++){
            while(!s.empty() && nums[s.top()] < nums[i]){
                res[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        for(int i = 0; i < n; i ++){
            while(!s.empty() && nums[s.top()] < nums[i]){
                if(res[s.top()] == -1)
                    res[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};
