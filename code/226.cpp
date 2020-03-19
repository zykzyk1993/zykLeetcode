/*
 * 226. 翻转二叉树
 * 难度：简单
 * 分类：树
 * 算法：简单递归模拟翻转
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return NULL;
        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;
    }
};
