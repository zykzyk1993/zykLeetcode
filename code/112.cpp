/*
 * 112. 路径总和
 * 题意：是否存在 从根节点到叶子节点 路径总和等于给定目标和的路径
 * 难度：简单
 * 分类：二叉树
 * 算法：dfs，每次减去当前root值，最后判断
 */
class Solution {
public:
    bool flag;

    void dfs(TreeNode* root, int targetSum) {
        if (flag || root == nullptr) {
            return;
        }
        targetSum -= root->val;
        if (root->left == nullptr && root->right == nullptr && targetSum == 0) {
            flag = true;
            return;
        }
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return flag;
    }
};
