/*
 * 129. 求根节点到叶节点数字之和
 * 题意：将根节点到叶节点的路径从高位到低位组成数字，求二叉树种所有这样的数字之和
 * 难度：中等
 * 分类：二叉树
 * 算法：辅助递归函数，递归遍历即可，保存sum变量
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode * root, int cur, int &res) {
        cur = 10 * cur + root->val;
        if (!root->left && !root->right) {
            res += cur;
        }
        else {
            if (root->left) {
                helper(root->left, cur, res);
            }
            if (root->right) {
                helper(root->right, cur, res);
            }
        }
    }
    int sumNumbers(TreeNode* root) {
        int res = 0;
        helper(root, 0, res);
        return res;
    }
};
