/*
 * 110. 平衡二叉树
 * 题意：判断该树是不是平衡二叉树
 * 难度：简单
 * 分类：树
 * 算法：利用获取最大高度的函数，左右子树高度相差超过1则设为-1，以此记录是否平衡
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
    int getMaxHeight(TreeNode* root){
        if(!root)return 0;
        int left = getMaxHeight(root->left);
        int right = getMaxHeight(root->right);
        if(left == -1 || right == -1){
            return -1;
        }
        else if(left > right + 1 || right > left + 1){
            return -1;
        }else{
            return max(left, right)+1;
        }
    }
    bool isBalanced(TreeNode* root) {
        return getMaxHeight(root) >= 0; 
    }
};
