/*
 * 111. 二叉树的最小深度
 * 题意：如题
 * 难度：简单
 * 分类：树
 * 算法：递归，空节点返回0，否则返回两个子节点(如果有)的最小高度
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
    int minDepth(struct TreeNode* root){
        if (root == NULL)
            return 0;
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        if (root->left == NULL && root->right != NULL)
            return 1 + rightDepth;
        if (root->left != NULL && root->right == NULL)
            return 1 + leftDepth;
        return leftDepth <= rightDepth ? leftDepth + 1: rightDepth + 1;
    }
};
