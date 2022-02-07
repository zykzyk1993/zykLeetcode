/*
 * 669. 修剪二叉搜索树
 * 题意：删除二叉搜索树中超过指定范围的节点
 * 难度：中等
 * 分类：树
 * 算法：递归，分为根结点是否需要删除两种情况
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root){
            return NULL;
        }
        if(root->val < low){
            return trimBST(root->right, low, high);
        }
        if(root->val > high){
            return trimBST(root->left, low, high);
        }
        root->right = trimBST(root->right, low, high);
        root->left = trimBST(root->left, low, high);
        return root;
    }
};
