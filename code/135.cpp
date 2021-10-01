/*
 * 135. 分发糖果
 * 题意：评分比两边高的孩子必须比两边获得的糖果多，最少1个，求最小值
 * 难度：困难
 * 分类：贪心
 * 算法：两个方向遍历，如果比前一个高，则取前一个糖果+1，否则为1，最终取两个方向的最大值
 */

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), res = 0;
        vector<int> forward_candys(n, 1), backward_candys(n, 1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                forward_candys[i] = forward_candys[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                backward_candys[i] = backward_candys[i+1]+1;
            }
        }
        for(int i=0;i<n;i++){
            res+=max(forward_candys[i], backward_candys[i]);
        }
        return res;
    }
};
