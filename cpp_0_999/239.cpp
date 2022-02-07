/*
 * 239. 滑动窗口最大值
 * 只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位，返回滑动窗口中的最大值
 * 难度：困难
 * 分类：滑动窗口 双端队列
 * 算法：使用双端队列，队尾操作保持单调递减，并且每次判断队头出队
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        for(int i=0;i<nums.size();i++){
            while(!dq.empty()&&nums[dq.back()]<=nums[i])dq.pop_back();
            dq.push_back(i);
            while(!dq.empty()&&(i-dq.front()>=k))dq.pop_front();
            if(i>=(k-1))ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
