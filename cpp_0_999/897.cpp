/*
 * 897. 递增顺序搜索树
 * 题意：按照中序遍历结果将其排成只有右结点的一字形树
 * 难度：简单
 * 分类：树
 * 算法：反向中序遍历，用ans记录最左侧结点，然后将左指针置为空
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
    void inorder(TreeNode *node, TreeNode*& ans) {
        if (node == nullptr) return;
        inorder(node->right, ans);
        node->right = ans;
        ans = node;
        inorder(node->left, ans);
        node->left = nullptr;
    }

    TreeNode *increasingBST(TreeNode *root) {
        TreeNode* ans = nullptr;
        inorder(root, ans);
        return ans;
    }
};
