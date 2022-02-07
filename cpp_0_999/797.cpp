/*
 * 797. 所有可能的路径
 * 题意：返回一个图结构中，从0号节点到n-1号节点所有可能的路径
 * 难度：中等
 * 分类：图 回溯
 * 算法：dfs回溯的方式从0开始遍历整个图
 */
class Solution {
public:
    vector<vector<int>> res;
    vector<int> stack;
    int n;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        stack.push_back(0);
        helper(graph, 0);
        return res;
    }
    void helper(vector<vector<int>>& graph, int cur){
        if(cur == n-1){
            res.push_back(stack);
        }
        for(auto &next:graph[cur]){
            stack.push_back(next);
            helper(graph, next);
            stack.pop_back();
        }
    }
};
