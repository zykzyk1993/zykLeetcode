/*
 * 1373. 二叉搜索子树的最大键值和
 * 题意：给定二叉树，返回二叉搜索子树的最大节点和
 * 难度：困难
 * 分类：二叉树
 * 算法：辅助函数，同时保存四个变量：是否为BST，节点和，该树最小值，该树最大值，其中后三个只在第一个有效时起作用
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
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        vector<int> info(4, 0);
        helper(root, info, ans);
        return ans;
    }
    /**
     * 1. isBST 2. sum 3. min 4. max
     */
    void helper(TreeNode *root, vector<int> &info, int &ans){
        if(!root){
            info[0] = 1;
            info[1] = 0;
            return;
        }
        vector<int> left_info(4, 0);
        helper(root->left, left_info, ans);
        vector<int> right_info(4, 0);
        helper(root->right, right_info, ans);
        if(left_info[0] == 0 || right_info[0] == 0){
            info[0] = 0;
            return;
        }
        if((root->left && left_info[3] >= root->val) || (root->right && right_info[2] <= root->val)){
            info[0] = 0;
            return;
        }
        info[0] = 1;
        info[1] = left_info[1] + right_info[1] + root->val;
        info[2] = root->left?left_info[2]:root->val;
        info[3] = root->right?right_info[3]:root->val;
        ans = max(ans, info[1]);
        return;
    }
};
