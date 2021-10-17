/*
 * 95. 不同的二叉搜索树 II
 * 题意：给定n，求1到n的所有二叉搜索树
 * 难度：中等
 * 分类：树
 * 算法：建立辅助函数，递归
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
    vector<TreeNode*> helper(int start, int end){
        if(start > end){
            return {NULL};
        }
        vector<TreeNode*> res;
        for(int i = start; i <= end; i++){
            vector<TreeNode*> lefts = helper(start, i-1);
            vector<TreeNode*> rights = helper(i+1, end);
            for(auto &left:lefts){
                for(auto &right:rights){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
};
