/*
 * 384. 打乱数组
 * 题意：提供随机shuffle数组，以及返回原数组的api
 * 难度：中等
 * 分类：数学
 * 算法：用成员变量保存原数组，然后使用洗牌算法，从后往前，i与前i个随机交换
 */
class Solution {
public:
    vector<int> origin;
    Solution(vector<int>& nums) {
        origin = nums;
    }
    
    vector<int> reset() {
        return origin;
    }
    
    vector<int> shuffle() {
        if(origin.empty())return {};
        int n = origin.size();
        vector<int> shuffle(origin);
        for(int i = n - 1; i >= 0; --i){
            swap(shuffle[i], shuffle[rand() % (i+1)]);
        }
        return shuffle;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
