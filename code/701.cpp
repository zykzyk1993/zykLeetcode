/*
 * 701. 二叉搜索树中的插入操作
 * 题意：二叉搜索树插入指定元素，保证合法即可
 * 难度：中等
 * 分类：二叉树
 * 算法：逐层向下寻找，如果root大于targe且左为空，则可以插入，反过来也可以，否则向下查找
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) {
            return new TreeNode(val);
        }
        TreeNode * ans = root;
        TreeNode* newNode = new TreeNode(val);
        while(true) {
            if (root->val < val) {
                if (root->right == NULL) {
                    root->right = newNode;
                    return ans;
                }
                else{
                    root = root->right;
                }
            }
            else {
                if (root->left == NULL) {
                    root->left = newNode;
                    return ans;
                }
                else{
                    root = root->left;
                }
            }
        }
    }
};
