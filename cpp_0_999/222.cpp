/*
 * 222. 完全二叉树的节点个数
 * 题意：给定完全二叉树求节点个数
 * 难度：中等
 * 分类：树
 * 算法：一直往左或一直往右，如果数目相等，则是一颗满二叉树，可以直接得出结果，否则递归判断左右子树
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
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int left_depth = 1;
        TreeNode* p = root;
        while(p->left){
            p = p->left;
            left_depth++;
        }
        p = root;
        int right_depth = 1;
        while(p->right){
            p = p->right;
            right_depth++;
        }
        if(left_depth == right_depth){
            return (1 << left_depth) - 1;
        }else{
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
};
