/*
 * 530. 二叉搜索树的最小绝对差
 * 题意：
 * 难度：简单
 * 分类：树
 * 算法：记录前驱的中序遍历
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
    void inOrder(TreeNode *root, TreeNode *&pre,int &ans){
        if(!root)
            return;
        if(root->left){
            inOrder(root->left, pre, ans);
        }
        if(pre && root->val - pre->val < ans){
            ans = root->val - pre->val;
        }
        pre = root;
        if(root->right){
            inOrder(root->right, pre, ans);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        TreeNode * pre = NULL;
        inOrder(root, pre, ans);
        return ans;
    }
};
