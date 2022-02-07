/*
 * 113. 路径总和 II
 * 题意：找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径
 * 难度：中等
 * 分类：二叉树
 * 算法：dfs，每次减去当前root值，递归终止为空节点
 */
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;

    void dfs(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return;
        }
        path.emplace_back(root->val);
        targetSum -= root->val;
        if (root->left == nullptr && root->right == nullptr && targetSum == 0) {
            ret.emplace_back(path);
        }
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ret;
    }
};
