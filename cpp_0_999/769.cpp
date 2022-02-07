/*
 * 769. 最多能完成排序的块
 * 题意：数组为0～n-1，尽可能多切块，保证每个块内排序后数组升序
 * 难度：中等
 * 分类：数组 贪心
 * 算法：只需要更新最大值, 如果遍历至当前，最大值为当前索引，则结果+1，多切一份
 */
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0, cur_max = 0;
        for(int i = 0; i < arr.size(); i ++){
            if(arr[i] > cur_max){
                cur_max = arr[i];
            }
            if(i == cur_max){
                ans ++;
            }
        }
        return ans;
    }
};
