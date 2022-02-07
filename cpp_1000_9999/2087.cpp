/*
 * 2087. 网格图中机器人回家的最小代价
 * 题意：机器人走到每个行列都有对应代价，求最小的代价走回家
 * 难度：中等
 * 分类：数组 贪心
 * 算法：实际上解是固定的，先后顺序无所谓，只要计算对应方向的每个cost之和就行
 */
class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int res = 0;
        if(startPos[0] < homePos[0]){
            for(int i = startPos[0] + 1; i <= homePos[0]; i ++){
                res += rowCosts[i];
            }
        }
        if(startPos[0] > homePos[0]){
            for(int i = homePos[0]; i < startPos[0]; i ++){
                res += rowCosts[i];
            }
        }
        if(startPos[1] < homePos[1]){
            for(int i = startPos[1] + 1; i <= homePos[1]; i ++){
                res += colCosts[i];
            }
        }
        if(startPos[1] > homePos[1]){
            for(int i = homePos[1]; i < startPos[1]; i ++){
                res += colCosts[i];
            }
        }
        return res;
    }
};
