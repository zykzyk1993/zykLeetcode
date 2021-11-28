/*
 * 699. 掉落的方块
 * 题意：持续掉落正方形方块，有交叠的时候，方块会粘附叠加，求每一时刻的最高高度
 * 难度：困难
 * 分类：模拟 线段树
 * 算法：反向思考，每个掉落的方块，对其之后的方块有影响，如果有交叠的话，其起始高度至少是当前方块
 */
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        vector<int> res(n, 0);
        for(int i = 0; i < n; i ++){
            int left = positions[i][0];
            int size = positions[i][1];
            int right = left + size;
            res[i] += size; //真正掉落，更新该方块高度
            for(int j = i+1; j < n; j ++){
                int left2 = positions[j][0];
                int size2 = positions[j][1];
                int right2 = left2+size2;
                if(left2 < right && right2 > left){
                    res[j] = max(res[j], res[i]); //以后掉落方块的时候，其起始高度可能已经受影响了
                }
            }
        }
        vector<int> ans; //遍历res，保留当前时刻最大值
        int cur = 0;
        for(auto &x:res){
            cur = max(cur, x);
            ans.push_back(cur);
        }
        return ans;
    }
};
