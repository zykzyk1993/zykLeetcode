/*
 * 659. 分割数组为连续子序列
 * 题意：判断是否能将给定数组分割为多个长度至少为3的序列
 * 难度：中等
 * 分类：数组 哈希表
 * 算法：两个哈希表，记录剩余i的频次，以及以i结尾的序列个数，对于剩余超过0的i，优先排在前一个数字序列之后，否则只能判断是否能以i起头
 */
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> m; //保留i的频次
        unordered_map<int, int> seq_m; //保留以i结尾的序列个数
        for(auto &num:nums) {
            m[num]++;
        }
        for(auto &num:nums){
            int freq = m[num];
            if(freq == 0) { //已经被排掉了
                continue;
            }
            m[num] --;
            if(seq_m[num - 1] > 0) {
                seq_m[num] ++; // 直接接在后面
                seq_m[num-1] --;
                continue;
            }
            else {
                if(m[num+1] > 0 && m[num+2] > 0) {
                    m[num+1] --;
                    m[num+2] --;
                    seq_m[num+2] ++;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
