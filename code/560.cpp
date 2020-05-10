/*
 * 560. 和为K的子数组
 * 给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数
 * 难度：中等
 * 分类：前缀和
 * 算法：典型前缀和，保存前缀和为sum的数量，并每次累加前缀和为sum-k的数量
 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(),sum=0,res=0;
        unordered_map<int,int> m;
        m[0]=1;
        for(auto num:nums){
            sum+=num;
            if(m.count(sum-k)>0){
                res+=m[sum-k];
            }
            m[sum]++;
        }
        return res;
    }
};
