/*
 * 404. 左叶子之和
 * 题意：求一棵树的所有左叶子之和
 * 难度：简单
 * 分类：树
 * 算法：辅助函数，判断当前结点是否是左子结点
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
    void helper(TreeNode* root, int &ans, bool is_left){
        if(!root) return;
        if(!root->left && !root->right && is_left){
            ans += root->val;
        }else{
            helper(root->left, ans, true);
            helper(root->right, ans, false);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        helper(root, ans, false);
        return ans;
    }
};
