/*
 * 646. 最长数对链
 * 题意：第二个数大于等于第一个数的数对，a,b c,d必须b<c才可以形成子序列，求最长子序列
 * 难度：中等
 * 分类：贪心
 * 算法：先按照第二个元素排序，贪心计算每个元素是否能加到子序列末尾
 */
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](vector<int>& p1, vector<int>& p2){
            return p1[1] < p2[1];
        });
        vector<vector<int>> dp;
        dp.push_back(pairs[0]);
        for(int i = 1; i < n; i++){
            if(pairs[i][0] > dp.back()[1]){
                dp.push_back(pairs[i]);
            }
        }
        return dp.size();
    }
};
