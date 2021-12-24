/*
 * 2090.半径为k的子数组平均值
 * 题意：对于半径为k全部落在数组内的，返回半径内的和，否则返回-1
 * 难度：中等
 * 分类：数组 模拟
 * 算法：按顺序相加，如果超过2*k(右边界)，则需要保存结果，并减去最左侧即将出半径的数据
 */
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> res(nums.size(), -1);
        if(nums.size() < 2 * k + 1){
            return res;
        }
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(i >= 2 * k){
                res[i - k] = sum / (2 * k + 1);
                sum -= nums[i - 2 * k];
            }
        }
        return res;
    }
};
